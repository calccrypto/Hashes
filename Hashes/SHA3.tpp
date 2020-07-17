// //////////////////////////////////////////////////////////////////////////////////////////
template <const unsigned int d, typename Valid>
typename SHA3 <d, Valid>::StateArray SHA3 <d, Valid>::s2sa(const std::string & S) const {
    SHA3 <d, Valid>::StateArray A = {{0}};
    for(uint8_t y = 0; y < 5; y++) {
        for(uint8_t x = 0; x < 5; x++) {
            A[x][y] = toint(little_end(S.substr(w * (5 * y + x), w), 2), 2);
        }
    }
    return A;
}

template <const unsigned int d, typename Valid>
std::string SHA3 <d, Valid>::sa2s(const typename SHA3 <d, Valid>::StateArray & A) const {
    std::string S = "";
    for(uint8_t j = 0; j < 5; j++) {
        for(uint8_t i = 0; i < 5; i++) {
            S += little_end(makebin(A[i][j], 64), 2);
        }
    }

    return S;
}

template <const unsigned int d, typename Valid>
typename SHA3 <d, Valid>::StateArray SHA3 <d, Valid>::theta(const typename SHA3 <d, Valid>::StateArray & A) const {
    SHA3 <d, Valid>::StateArray Aprime = A;

    // step 1
    std::array <uint64_t, 5> C;
    for(uint8_t x = 0; x < 5; x++) {
        C[x] = A[x][0] ^ A[x][1] ^ A[x][2] ^ A[x][3] ^ A[x][4];
    }

    // step 2
    std::array <uint64_t, 5> D;
    for(uint8_t x = 0; x < 5; x++) {
        D[x] = C[(x + 4) % 5] ^ ROL(C[(x + 1) % 5], 1, 64);

        // step 3
        for(uint8_t y = 0; y < 5; y++) {
            Aprime[x][y] = A[x][y] ^ D[x];
        }
    }

    return Aprime;
}

template <const unsigned int d, typename Valid>
typename SHA3 <d, Valid>::StateArray SHA3 <d, Valid>::pirho(const typename SHA3 <d, Valid>::StateArray & A) const {
    SHA3 <d, Valid>::StateArray Aprime;
    for(uint8_t x = 0; x < 5; x++) {
        for(uint8_t y = 0; y < 5; y++) {
            Aprime[y][(2 * x + 3 * y) % 5] = ROL(A[x][y], Keccak_rot[x][y], 64);
        }
    }
    return Aprime;
}

template <const unsigned int d, typename Valid>
typename SHA3 <d, Valid>::StateArray SHA3 <d, Valid>::chi(const typename SHA3 <d, Valid>::StateArray & A) const {
    SHA3 <d, Valid>::StateArray Aprime = A;
    for(uint8_t x = 0; x < 5; x++) {
        for(uint8_t y = 0; y < 5;  y++) {
            Aprime[x][y] = A[x][y] ^ ((~A[(x + 1) % 5][y]) & A[(x + 2) % 5][y]);
        }
    }
    return Aprime;
}

template <const unsigned int d, typename Valid>
typename SHA3 <d, Valid>::StateArray SHA3 <d, Valid>::iota(const typename SHA3 <d, Valid>::StateArray & A, const uint64_t rc) const {
    SHA3 <d, Valid>::StateArray Aprime = A;
    Aprime[0][0] ^= rc;
    return Aprime;
}

// assumes S is already in binary
template <const unsigned int d, typename Valid>
typename std::string SHA3 <d, Valid>::f(const std::string & S) const {
    SHA3 <d, Valid>::StateArray A = s2sa(S);

    for(unsigned int i = 0; i < nr; i++) {
        A = iota(chi(pirho(theta(A))), Keccak_RC[i]);
    }

    return sa2s(A);
}
// //////////////////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////////////////
// absorb data into given state
template <const unsigned int d, typename Valid>
void SHA3 <d, Valid>::absorb(std::string & S, const std::string & P) const {
    for(unsigned int i = 0; i < P.size(); i += r) {
        for(int j = 0; j < r; j++) {
            S[j] = (P[i + j] ^ S[j]) | '0';
        }

        S = f(S);
    }
}

// squeeze output data (concatenate results of f)
template <const unsigned int d, typename Valid>
std::string SHA3 <d, Valid>::squeeze(std::string & S) const {
    std::string Z = "";
    while (d > Z.size()) {
        Z += S.substr(0, r);
        S = f(S);
    }
    return Z.substr(0, d);
}


template <const unsigned int d, typename Valid>
SHA3 <d, Valid>::SHA3()
    : HashAlg(),
      b(1600), w(64), l(6), nr(24),
      state((size_t) 1600, (char) '0'), stack(""),
      r(1600 - (d << 1))
{}

template <const unsigned int d, typename Valid>
SHA3 <d, Valid>::SHA3(const std::string & M)
    : SHA3()
{
    update(M);
}

template <const unsigned int d, typename Valid>
void SHA3 <d, Valid>::update(const std::string & M) {
    // process old leftover data + new data up to last full block
    std::string data = stack + binify(M);
    absorb(state, data.substr(0, (data.size() / r) * r));

    // clear old stack (in case new data does not have partial blocks)
    stack = "";

    // extract last block of M
    if (unsigned int rem = data.size() % r) {
        stack = data.substr(data.size() - rem, rem);
    }
}

template <const unsigned int d, typename Valid>
std::string SHA3 <d, Valid>::digest() {
    // pad10*1 embedded here ////////////////////////////
    std::string m = stack + "00000110";
    int pad_size = (-static_cast <int> (m.size()) - 1) % r;
    pad_size = (pad_size + r) % r;
    m += std::string(pad_size - 7, '0') + "10000000";
    // //////////////////////////////////////////////////

    // copy state and process on that instead of actual state
    std::string S = state;
    absorb(S, m);

    return unbinify(squeeze(S));
}

template <const unsigned int d, typename Valid>
std::string SHA3 <d, Valid>::hexdigest() {
    return hexlify(digest());
}

template <const unsigned int d, typename Valid>
std::size_t SHA3 <d, Valid>::blocksize() const {
    return r;
}

template <const unsigned int d, typename Valid>
std::size_t SHA3 <d, Valid>::digestsize() const {
    return d;
}
// //////////////////////////////////////////////////////////////////////////////////////////
