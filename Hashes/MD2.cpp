#include "./MD2.h"

void MD2::run(){
    std::string data = total;
    uint8_t pad = 16 - (data.size() & 15);
    data += std::string(pad, pad);
    std::string C(16, 0);
    uint8_t L = 0;
    for(unsigned int i = 0; i < data.size() >> 4; i++){
        for(uint8_t j = 0; j < 16; j++){
            C[j] ^= MD2_C[data[(i << 4) + j] ^ L];
            L = C[j];
        }
    }
    data += C;
    std::string X(48, 0);
    for(unsigned int i = 0; i < data.size() >> 4; i++){
        for(uint8_t j = 0; j < 16; j++){
            X[16 + j] = data[(i << 4) + j];
            X[32 + j] = X[16 + j] ^ X[j];
        }
        uint8_t t = 0;
        for(uint8_t j = 0; j < 18; j++){
            for(uint8_t k = 0; k < 48; k++){
                t = X[k] = X[k] ^ MD2_C[t];
            }
            t += j;// (t + j) % 256;
        }
    }
    hash = X.substr(0, 16);
}

MD2::MD2(const std::string & data){
    update(data);
}

std::string MD2::hexdigest(){
    return hexlify(hash);
}

unsigned int MD2::blocksize(){
    return 128;
};

unsigned int MD2::digestsize(){
    return 128;
};
