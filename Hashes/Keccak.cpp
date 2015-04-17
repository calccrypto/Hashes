#include "Keccak.h"

// //////////////////////////////////////////////////////////////////////////////////////////
// KECCAK-p[b, n_r] = base algorithm
// KECCAK-f[b] = KECCAK-p[b, 12 + 2 * l]
KECCAK_p::StateArray KECCAK_p::s2sa(const std::string & S) const {
    KECCAK_p::StateArray A = {{0}};
    for(uint8_t y = 0; y < 5; y++){
        for(uint8_t x = 0; x < 5; x++){
            // for(std::size_t z = 0; z < w; z++){
                // A[x][y].push_back((S[w * (5 * y + x) + z] == '1'));
            // }
            A[x][y] = toint(little_end(S.substr(w * (5 * y + x), w), 2), 2);
        }
    }
    return A;
}

std::string KECCAK_p::sa2s(const KECCAK_p::StateArray & A) const {
    // // transform state array into lanes (5 x 5)
    // std::array <std::array <std::string, 5>, 5> lanes;
    // for(uint8_t i = 0; i < 5; i++){
        // for(uint8_t j = 0; j < 5;  j++){
            // std::string lane = "";
            // for(unsigned int k = 0; k < w; k++){
                // lane += A[i][j][k]?"1":"0";
            // }
            // lanes[i][j] = lane;
        // }
    // }

    // // transform lanes into planes
    // std::array <std::string, 5> plane;
    // for(uint8_t j = 0; j < 5; j++){
        // for(uint8_t i = 0; i < 5; i++){
            // plane[j] += lanes[i][j];
        // }
    // }

    // // plane into string
    // std::string S = "";
    // for(const std::string & p : plane){
        // S += p;
    // }

    std::string S = "";
    for(uint8_t j = 0; j < 5; j++){
        for(uint8_t i = 0; i < 5; i++){
            // for(unsigned int k = 0; k < w; k++){
                // S += A[i][j][k]?"1":"0";
            // }
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
    // }

    // // step 3
    // for(uint8_t x = 0; x < 5; x++){
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

// KECCAK_p::StateArray KECCAK_p::rho(const KECCAK_p::StateArray & A){
   // KECCAK_p::StateArray Aprime = A;
   // for(unsigned int z = 0; z < w; z++){
       // Aprime[0][0] = A[0][0];
   // }

   // uint8_t x = 1,
           // y = 0;

    // for(uint8_t t = 0; t < 23; t++){
        // for(unsigned int z = 0; z < w; z++){
            // Aprime[x][y][z] = A[x][y][(z - (t + 1) * (t + 2) / 2) % w];
        // }
        // uint8_t temp = (2 * x + 3 * y) % 5;
        // x = y;
        // y = temp;
    // }

   // return Aprime;
// }

// KECCAK_p::StateArray KECCAK_p::pi(const KECCAK_p::StateArray & A){
    // KECCAK_p::StateArray Aprime = A;
    // for(uint8_t x = 0; x < 5; x++){
        // for(uint8_t y = 0; y < 5;  y++){
            // for(unsigned int z = 0; z < w; z++){
                // Aprime[x][y][z] = A[(x + 3 * y) % 5][x][z];
            // }
        // }
    // }
    // return Aprime;
// }

KECCAK_p::StateArray KECCAK_p::chi(const KECCAK_p::StateArray & A) const {
   KECCAK_p::StateArray Aprime = A;
    for(uint8_t x = 0; x < 5; x++){
        for(uint8_t y = 0; y < 5;  y++){
            Aprime[x][y] = A[x][y] ^ ((~A[(x + 1) % 5][y]) & A[(x + 2) % 5][y]);
        }
    }
    return Aprime;
}

// bool rc(int t){
    // if (!(t % 255)){
        // return 1;
    // }

    // std::string R = "\x01\x00\x00\x00\x00\x00\x00\x00";
    // for(int i = 0; i < (t % 255); i++){
        // R = std::string(1, 0) + R;
        // R[0] |= R[8];
        // R[4] |= R[8];
        // R[5] |= R[8];
        // R[6] |= R[8];
        // R = R.substr(0, 8);
    // }
    // return R[0];
// }

KECCAK_p::StateArray KECCAK_p::iota(const KECCAK_p::StateArray & A, const uint64_t rc) const {
   KECCAK_p::StateArray Aprime = A;

    Aprime[0][0] ^= rc;
    // std::string RC(w, 0);

    // for(uint8_t j = 0; j < l; j++){
        // RC[(1 << l) - 1] = rc(j + 7 * ir);
    // }

    // for(unsigned int z = 0; z < w; z++){
        // Aprime[0][0][z] ^= RC[z];
    // }

    return Aprime;
}

KECCAK_p::StateArray KECCAK_p::Rnd(const KECCAK_p::StateArray & A, const uint64_t rc) const {
    // return iota(chi(pi(rho(theta(A)))), rc);
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

// //////////////////////////////////////////////////////////////////////////////////////////
// pad10*1
// 5.1
// x is always positive
// unsigned int throws things off
std::string pad101(const int x, const int m){
    if (x < 1){
        throw std::invalid_argument("x in pad10*1 needs to be positive");
    }

    // return "1" + std::string((-m - 2 + x) % x, '0') + "1";
    int j = (-m - 2) % x;
    j = (j + x) % x;    // get rid of negative values

    return "1" + std::string(j, '0') + "1";
}
// //////////////////////////////////////////////////////////////////////////////////////////

// //////////////////////////////////////////////////////////////////////////////////////////
// Z = SPONGE[f, pad, r]
SPONGE::SPONGE(const KECCAK_p & func,
       std::function <std::string(const int, const int)> pad_func,
       unsigned int rate)
      : f(func), pad(pad_func), r(rate)
    {}

// M is already in binary form ('\x30' and '\x31' characters only)
std::string SPONGE::operator()(const std::string & M, const unsigned int d){
    std::string P = M + pad(r, M.size());
    // unsigned int n = P.size() / r,
                 // c = f.get_b() - r;

    // flip bit order
    for(unsigned int j = 0; j < P.size(); j+= 8){
        for(unsigned int k = 0; k < 4; k++){
            std::swap(P[j + k], P[j + 7 - k]);
        }
    }

    // absorb
    std::string S((size_t) f.get_b(), (char) '0');
    for(unsigned int i = 0; i < P.size(); i += r){
        // don't xor octets after index r - 1 since all octets after are 0
        for(unsigned int j = 0; j < r; j++){
            S[j] = (P[i + j] ^ S[j]) | '0';
        }

        S = f(S);
    }

    // squeeze
    std::string Z = "";
    while (d > Z.size()){
        Z += S.substr(0, r);
        S = f(S);
    }

    return Z.substr(0, d);
}
// //////////////////////////////////////////////////////////////////////////////////////////

// //////////////////////////////////////////////////////////////////////////////////////////
// KECCAK[c] (M, d) = SPONGE[KECCAK-p[1600, 24], pad10*1, 1600 – c] (M, d)
KECCAK::KECCAK(const unsigned int c):
    sponge(SPONGE(KECCAK_p(1600, 24), pad101, 1600 - c))
{}

std::string KECCAK::operator()(const std::string & M, const unsigned int d){
    return sponge(M, d);
}
// //////////////////////////////////////////////////////////////////////////////////////////

// //////////////////////////////////////////////////////////////////////////////////////////
// template <unsigned int d>
// SHA3 <d>::SHA3()
    // : hash(""), KECCAKC(d << 1)
// {}

// template <unsigned int d>
// SHA3 <d>::SHA3(const std::string & M)
    // : SHA32()
// {
    // operator()(M);
// }

// template <unsigned int d>
// void SHA3 <d>::operator()(const std::string & M){
    // std::string m = binify(M);

    // // flip bit order for padding
    // for(unsigned int j = 0; j < m.size(); j+= 8){
        // for(unsigned int k = 0; k < 4; k++){
            // std::swap(m[j + k], m[j + 7 - k]);
        // }
    // }

    // hash = unbinify(KECCAKC(m + "01", d));
// }

// template <unsigned int d>
// std::string SHA3 <d>::digest() const {
    // return hash;
// }

// template <unsigned int d>
// std::string SHA3 <d>::hexdigest() const {
    // return hexlify(hash);
// }

// template <const unsigned int d>
// unsigned int SHA3 <d>::blocksize() const {
    // return 1600 - (d << 1);
// }

// template <const unsigned int d>
// unsigned int SHA3 <d>::digestsize() const {
    // return d;
// }
// //////////////////////////////////////////////////////////////////////////////////////////