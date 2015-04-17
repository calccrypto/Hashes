#include "SHA3.h"

// //////////////////////////////////////////////////////////////////////////////////////////
KECCAK_p::StateArray KECCAK_p::s2sa(const std::string & S) const {
    KECCAK_p::StateArray A = {{0}};
    for(uint8_t y = 0; y < 5; y++){
        for(uint8_t x = 0; x < 5; x++){
            A[x][y] = toint(little_end(S.substr(w * (5 * y + x), w), 2), 2);
        }
    }
    return A;
}

std::string KECCAK_p::sa2s(const KECCAK_p::StateArray & A) const {
    std::string S = "";
    for(uint8_t j = 0; j < 5; j++){
        for(uint8_t i = 0; i < 5; i++){
            S += little_end(makebin(A[i][j], 64), 2);
        }
    }

    return S;
}

KECCAK_p::StateArray KECCAK_p::theta(const KECCAK_p::StateArray & A) const {
    KECCAK_p::StateArray Aprime = A;

    // step 1
    std::array <uint64_t, 5> C;
    for(uint8_t x = 0; x < 5; x++){
        C[x] = A[x][0] ^ A[x][1] ^ A[x][2] ^ A[x][3] ^ A[x][4];
    }

    // step 2
    std::array <uint64_t, 5> D;
    for(uint8_t x = 0; x < 5; x++){
        D[x] = C[(x + 4) % 5] ^ ROL(C[(x + 1) % 5], 1, 64);

        // step 3
        for(uint8_t y = 0; y < 5; y++){
            Aprime[x][y] = A[x][y] ^ D[x];
        }
    }

    return Aprime;
}

KECCAK_p::StateArray KECCAK_p::pirho(const KECCAK_p::StateArray & A) const {
    KECCAK_p::StateArray Aprime;
    for(uint8_t x = 0; x < 5; x++){
        for(uint8_t y = 0; y < 5; y++){
            Aprime[y][(2 * x + 3 * y) % 5] = ROL(A[x][y], Keccak_rot[x][y], 64);
        }
    }
    return Aprime;
}

KECCAK_p::StateArray KECCAK_p::chi(const KECCAK_p::StateArray & A) const {
    KECCAK_p::StateArray Aprime = A;
    for(uint8_t x = 0; x < 5; x++){
        for(uint8_t y = 0; y < 5;  y++){
            Aprime[x][y] = A[x][y] ^ ((~A[(x + 1) % 5][y]) & A[(x + 2) % 5][y]);
        }
    }
    return Aprime;
}

KECCAK_p::StateArray KECCAK_p::iota(const KECCAK_p::StateArray & A, const uint64_t rc) const {
    KECCAK_p::StateArray Aprime = A;
    Aprime[0][0] ^= rc;
    return Aprime;
}

KECCAK_p::KECCAK_p::StateArray KECCAK_p::Rnd(const KECCAK_p::StateArray & A, const uint64_t rc) const {
    return iota(chi(pirho(theta(A))), rc);
}

void KECCAK_p::print(const KECCAK_p::StateArray & A) const{
    for(int y = 0; y < 5; y++){
        for(int x = 0; x < 5; x++){
             std::cout << makehex(A[x][y], 16) << " ";
        }
        std::cout << std::endl;
    }
}

 KECCAK_p::KECCAK_p(const unsigned int B, const unsigned int Nr)
    : b(B), w(B / 25), l(log2(B / 25)), nr(Nr)
{
    if (l > 6){
        throw std::invalid_argument("b should be one of the values in Table 1 of FIPS 202.");
    }
}

// assumes S is already in binary
std::string KECCAK_p::operator()(const std::string & S) const {
    KECCAK_p::StateArray A = s2sa(S);

    for(unsigned int i = 0; i < nr; i++){
        A = Rnd(A, Keccak_RC[i]);
    }

    return sa2s(A);
}

unsigned int KECCAK_p::get_b() const {
    return b;
}
// //////////////////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////////////////
// absorb data into given state
template <const unsigned int d>
void SHA3 <d>::absorb(std::string & S, const std::string & P) const {
    for(unsigned int i = 0; i < P.size(); i += r){
        for(int j = 0; j < r; j++){
            S[j] = (P[i + j] ^ S[j]) | '0';
        }

        S = f(S);
    }
}

// squeeze output data (concatenate results of f)
template <const unsigned int d>
std::string SHA3 <d>::squeeze(std::string & S) const {
    std::string Z = "";
    while (d > Z.size()){
        Z += S.substr(0, r);
        S = f(S);
    }
    return Z.substr(0, d);
}

template <const unsigned int d>
SHA3 <d>::SHA3()
    : state((size_t) 1600, (char) '0'), stack(""),
    f(KECCAK_p(1600, 24)), r(1600 - (d << 1))
{}

template <const unsigned int d>
SHA3 <d>::SHA3(const std::string & M)
    : SHA3()
{
    update(M);
}

template <const unsigned int d>
void SHA3 <d>::update(const std::string & M){
    // process old leftover data + new data up to last full block
    std::string data = stack + binify(M);
    absorb(state, data.substr(0, (data.size() / r) * r));

    // clear old stack (in case new data does not have partial blocks)
    stack = "";

    // extract last block of M
    if (unsigned int rem = data.size() % r){
        stack = data.substr(data.size() - rem, rem);
    }
}

template <const unsigned int d>
std::string SHA3 <d>::digest(){
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

template <const unsigned int d>
std::string SHA3 <d>::hexdigest(){
    return hexlify(digest());
}

template <const unsigned int d>
unsigned int SHA3 <d>::blocksize() const {
    return r;
}

template <const unsigned int d>
unsigned int SHA3 <d>::digestsize() const {
    return d;
}
// //////////////////////////////////////////////////////////////////////////////////////////