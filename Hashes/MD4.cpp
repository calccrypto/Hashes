#include "MD4.h"

void MD4::run(const std::string & data, context & state) const {
    for(unsigned int i = 0; i < (data.size() >> 6); i++){
        uint32_t a = state.h0, b = state.h1, c = state.h2, d = state.h3;
        std::string W = data.substr(i << 6, 64);
        uint32_t w[16];
        for(uint8_t x = 0; x < 16; x++){
            w[x] = toint(W.substr(x << 2, 4), 256);
        }
        for(uint8_t x = 0; x < 48; x++){
            uint32_t F[4] = {(b & c) | ((~b) & d), ((b & c) | (b & d) | (c & d)) + 0x5a827999, (b ^ c ^ d) + 0x6ed9eba1};
            uint32_t f = F[x >> 4];
            uint32_t K[3][16];
            for(uint8_t y = 0; y < 16; y++){
                K[0][y] = y;
            }
            for(uint8_t y = 0; y < 16; y++){
                K[1][y] = 4 * (y & 3) + (y >> 2);
            }
            K[2][0] = 0; K[2][1] = 8; K[2][2] = 4; K[2][3] = 12; K[2][4] = 2; K[2][5] = 10; K[2][6] = 6; K[2][7] = 14; K[2][8] = 1; K[2][9] = 9; K[2][10] = 5; K[2][11] = 13; K[2][12] = 3; K[2][13] = 11; K[2][14] = 7; K[2][15] = 15;
            uint32_t k[16];
            for(uint8_t y = 0; y < 16; y++){
                k[y] = K[x >> 4][y];
            }
            uint32_t t = d;
            d = c;
            c = b;
            b = ROL(a + f + w[k[x & 15]], MD4_R[x >> 4][x & 3], 32);
            a = t;
        }
        state.h0 += a;
        state.h1 += b;
        state.h2 += c;
        state.h3 += d;
    }
}

MD4::MD4():
    MerkleDamgard(),
    ctx(0x67452301, 0xefcdab89, 0x98badcfe, 0x10325476)
{
}

MD4::MD4(const std::string & data):
    MD4()
{
    update(data);
}

void MD4::update(const std::string & data){
    clen += data.size();
    stack += data;

    std::string temp = "";
    for(unsigned int i = 0; i < ((clen >> 6) << 6); i += 4){
        temp += little_end(stack.substr(i, 4), 256);
    }
    run(temp, ctx);
    stack = stack.substr(stack.size() - (stack.size() & 63), 64);
}

std::string MD4::hexdigest(){
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

std::size_t MD4::blocksize() const {
    return 512;
}

std::size_t MD4::digestsize() const {
    return 128;
}
