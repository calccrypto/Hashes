#include "MD2.h"

void MD2::checksum(std::string & c, const std::string & data){
    for(uint8_t j = 0; j < 16; j++){
        c[j] ^= MD2_C[data[j] ^ L];
        L = c[j];
    }
}

void MD2::process(std::string & x, const std::string & data){
    for(uint8_t j = 0; j < 16; j++){
        x[16 + j] = data[j];
        x[32 + j] = x[16 + j] ^ x[j];
    }
    uint8_t t = 0;
    for(uint8_t j = 0; j < 18; j++){
        for(uint8_t k = 0; k < 48; k++){
            t = x[k] = x[k] ^ MD2_C[t];
        }
        t += j;// (t + j) & 255;
    }
}

MD2::MD2():
    MerkleDamgard(),
    L(0),
    C(std::string(16, 0)),
    X(std::string(48, 0))
{
}

MD2::MD2(const std::string & data):
    MD2()
{
    update(data);
}

void MD2::update(const std::string & data){
    stack += data;
    for(unsigned int i = 0; i < (stack.size() >> 4); i++){
        std::string temp = data.substr(i << 4, 16);
        checksum(C, temp);
        process(X, temp);
    }
    stack = stack.substr(stack.size() - (stack.size() & 15), 16);
}

std::string MD2::hexdigest(){
    uint8_t pad = 16 - (stack.size() & 15);
    std::string data = stack + std::string(pad, pad);
    std::string c = C;
    checksum(c, data);
    std::string x = X;
    process(x, data);
    process(x, c);
    return hexlify(x.substr(0, 16));
}

unsigned int MD2::blocksize() const{
    return 128;
};

unsigned int MD2::digestsize() const{
    return 128;
};
