#include "./MD4.h"

void MD4::run(){
    h0 = 0x67452301;
    h1 = 0xefcdab89;
    h2 = 0x98badcfe;
    h3 = 0x10325476;
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
        uint32_t a = h0, b = h1, c = h2, d = h3;
        std::string W = data.substr(64 * i, 64);
        uint32_t w[16];
        for(uint8_t x = 0; x < 16; x++){
            w[x] = toint(W.substr(x << 2, 4), 256);
        }
        for(uint8_t x = 0; x < 48; x++){
            uint32_t F[4] = {(b & c) | ((~b) & d), ((b & c) | (b & d) | (c & d)) + 0x5a827999, (b ^ c ^ d) + 0x6ed9eba1};
            uint32_t f = F[x / 16];
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
            b = ROL((a + f + w[k[x & 15]]) & mod32, MD4_R[x >> 4][x & 3], 32);
            a = t;
        }
        h0 += a;
        h1 += b;
        h2 += c;
        h3 += d;
    }
}

MD4::MD4(const std::string & str){
    update(str);
}

std::string MD4::hexdigest(){
    return little_end(makehex(h0 & mod32, 8)) + little_end(makehex(h1 & mod32, 8)) + little_end(makehex(h2 & mod32, 8)) + little_end(makehex(h3 & mod32, 8));
}

unsigned int MD4::blocksize() {
    return 512;
}

unsigned int MD4::digestsize(){
    return 128;
}
