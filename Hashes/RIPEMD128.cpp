#include "RIPEMD128.h"

uint32_t RIPEMD128::F(const uint32_t & x, const uint32_t & y, const uint32_t & z, const uint8_t round) const{
    if (round < 16){
        return x ^ y ^ z;
    }
    else if (16 <= round && round < 32){
        return (x & y) | (~x & z);
    }
    else if (32 <= round && round < 48){
        return (x | ~y) ^ z;
    }
    else{ //if (48 <= round && round < 64)
        return (x & z) | (y & ~z);
    }
}

void RIPEMD128::run(const std::string & data, context & state) const{
    for(unsigned int i = 0; i < (data.size() >> 6); i++){
        uint32_t a = state.h0, b = state.h1, c = state.h2, d = state.h3, A = state.h0, B = state.h1, C = state.h2, D = state.h3;
        uint32_t X[16];
        for(uint8_t j = 0; j < 16; j++){
            X[j] = toint(data.substr(i << 6, 64).substr(j << 2, 4), 256);
        }
        uint32_t T;
        for(uint8_t j = 0; j < 64; j++){
            T = ROL(a + F(b, c, d, j) + X[RIPEMD_r[j]] + RIPEMD128_k[j >> 4], RIPEMD_s[j], 32);
            a = d; d = c; c = b; b = T;
            T = ROL(A + F(B, C, D, 63 - j) + X[RIPEMD_R[j]] + RIPEMD128_K[(j >> 4)], RIPEMD_S[j], 32);// + 1 to RIPEMD_K because constants are for RIPEMD160
            A = D; D = C; C = B; B = T;
        }
        T        = state.h1 + c + D;
        state.h1 = state.h2 + d + A;
        state.h2 = state.h3 + a + B;
        state.h3 = state.h0 + b + C;
        state.h0 = T;
    }
}

RIPEMD128::RIPEMD128(): 
    MerkleDamgard(),
    ctx(RIPEMD_H0, RIPEMD_H1, RIPEMD_H2, RIPEMD_H3)
{
}

RIPEMD128::RIPEMD128(const std::string & data):
    RIPEMD128()
{
    update(data);
}

void RIPEMD128::update(const std::string & data){
    clen += data.size();
    stack += data;

    std::string temp = "";
    for(unsigned int i = 0; i < ((clen >> 6) << 6); i += 4){
        temp += little_end(stack.substr(i, 4), 256);
    }
    run(temp, ctx);
    stack = stack.substr(stack.size() - (stack.size() & 63), 64);
}

std::string RIPEMD128::hexdigest(){
    context out = ctx;
    std::string data = stack + "\x80" + std::string((((clen & 63) > 55)?119:55) - (clen & 63), 0);

    std::string temp = "";
    for(unsigned int i = 0; i < data.size(); i += 4){
        temp += little_end(data.substr(i, 4), 256);
    }

    std::string len = unhexlify(makehex(clen << 3, 16));
    temp += len.substr(4, 4) + len.substr(0, 4);

    run(temp, out);

    return little_end(makehex(out.h0, 8), 16) + little_end(makehex(out.h1, 8), 16) + little_end(makehex(out.h2, 8), 16) + little_end(makehex(out.h3, 8), 16);
}

std::size_t RIPEMD128::blocksize() const{
    return 512;
}

std::size_t RIPEMD128::digestsize() const{
    return 128;
}
