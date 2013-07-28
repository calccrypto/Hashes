#include "./RIPEMD128.h"

uint32_t RIPEMD128::F(const uint32_t & x, const uint32_t & y, const uint32_t & z, const uint8_t round){
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

void RIPEMD128::run(){
    h0 = RIPEMD_H0; h1 = RIPEMD_H1; h2 = RIPEMD_H2; h3 = RIPEMD_H3;
    std::string data = total;
    unsigned int length = (data.size() << 3) & mod64;
    data += "\x80";
    while (data.size() % 64 != 56){
        data += std::string("\x00", 1);
    }
    std::string temp = "";
    for(unsigned int x = 0; x < data.size() >> 2; x++){
        temp += little_end(data.substr(x << 2, 4), 256);
    }
    data = temp;
    temp = unhexlify(makehex(length, 16));
    data += temp.substr(4, 4) + temp.substr(0, 4);
    for(unsigned int i = 0; i < (data.size() >> 6); i++){
        uint32_t a = h0, b = h1, c = h2, d = h3, A = h0, B = h1, C = h2, D = h3;
        uint32_t X[16];
        for(uint8_t j = 0; j < 16; j++){
            X[j] = toint(data.substr(i << 6, 64).substr(j << 2, 4), 256);
        }
        uint32_t T;
        for(uint8_t j = 0; j < 64; j++){
            T = (ROL((a + F(b, c, d, j) + X[RIPEMD_r[j]] + RIPEMD128_k[j >> 4]) & mod32, RIPEMD_s[j], 32)) & mod32;
            a = d; d = c; c = b; b = T;
            T = (ROL((A + F(B, C, D, 63 - j) + X[RIPEMD_R[j]] + RIPEMD128_K[(j >> 4)]) & mod32, RIPEMD_S[j], 32)) & mod32;// + 1 to RIPEMD_K because constants are for RIPEMD160
            A = D; D = C; C = B; B = T;
        }
        T = h1 + c + D;
        h1 = h2 + d + A;
        h2 = h3 + a + B;
        h3 = h0 + b + C;
        h0 = T;
    }
}

RIPEMD128::RIPEMD128(const std::string & str){
    update(str);
}

std::string RIPEMD128::hexdigest(){
    return little_end(makehex(h0, 8)) + little_end(makehex(h1, 8)) + little_end(makehex(h2, 8)) + little_end(makehex(h3, 8));
}

unsigned int RIPEMD128::blocksize(){
    return 512;
}

unsigned int RIPEMD128::digestsize(){
    return 128;
}
