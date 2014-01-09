#include "./MD4.h"

void MD4::run(const std::string & data, uint32_t & H0, uint32_t & H1, uint32_t & H2, uint32_t & H3){
    for(unsigned int i = 0; i < (data.size() >> 6); i++){
        uint32_t a = h0, b = h1, c = h2, d = h3;
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
        H0 += a;
        H1 += b;
        H2 += c;
        H3 += d;
    }
}

MD4::MD4(const std::string & data){
    h0 = 0x67452301;
    h1 = 0xefcdab89;
    h2 = 0x98badcfe;
    h3 = 0x10325476;
    update(data);
}

void MD4::update(const std::string & data){
    bytes += data.size();
    buffer += data;

    std::string temp = "";
    for(unsigned int i = 0; i < ((bytes >> 6) << 6); i += 4){
        temp += little_end(buffer.substr(i, 4), 256);
    }
    run(temp, h0, h1, h2, h3);
    buffer = buffer.substr(buffer.size() - (buffer.size() & 63), 64);
}

std::string MD4::hexdigest(){
    uint32_t out0 = h0, out1 = h1, out2 = h2, out3 = h3;
    std::string data = buffer + "\x80" + std::string((((bytes & 63) > 55)?119:55) - (bytes & 63), 0);

    std::string temp = "";
    for(unsigned int i = 0; i < data.size(); i += 4){
        temp += little_end(data.substr(i, 4), 256);
    }

    std::string len = unhexlify(makehex(bytes << 3, 16));
    temp += len.substr(4, 4) + len.substr(0, 4);

    run(temp, out0, out1, out2, out3);

    return little_end(makehex(out0, 8), 16) + little_end(makehex(out1, 8), 16) + little_end(makehex(out2, 8), 16) + little_end(makehex(out3, 8), 16);
}

unsigned int MD4::blocksize() {
    return 512;
}

unsigned int MD4::digestsize(){
    return 128;
}
