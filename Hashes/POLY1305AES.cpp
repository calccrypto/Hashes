#include "./POLY1305AES.h"

POLY1305AES::POLY1305AES(const std::string & R, const std::string & NONCE){
    r = integer(little_end(zfill(hexlify(R), 32).substr(0, 32), 16), 16);
    nonce = zfill(NONCE, 16, zero).substr(0, 16);
    mod1305.fill(130);
    mod1305 -= 4;
}

void POLY1305AES::HASH(std::string KEY, std::string MESSAGE){
    KEY = zfill(KEY, 16, zero).substr(0, 16);
    std::string aes = little_end(hexlify(AES(KEY).encrypt(nonce)));
    unsigned int q = (MESSAGE.size() >> 4) + (bool) (MESSAGE.size() & 15);
    MESSAGE = hexlify(MESSAGE);
    std::vector <std::string> m;
    while (MESSAGE.size() >= 32){
        m.push_back("1" + little_end(MESSAGE.substr(0, 32), 16));
        MESSAGE = MESSAGE.substr(32, MESSAGE.size() - 32);
    }
    if (MESSAGE.size())
        m.push_back(zfill("1" + little_end(MESSAGE, 16), 33));
    integer h(aes, 16);
    for(unsigned int x = 0; x < q; x++){
        h += integer(m[x], 16) * POW(r, integer(q - x));
    }
    h %= mod1305;
    std::deque <uint8_t> final = h.data();
    while (final.size() > 16)
        final.pop_front();
    H = little_end(makehex(integer(final), 32), 16);
}

std::string POLY1305AES::hexdigest(){
    return H;
}

std::string POLY1305AES::digest(){
    return unhexlify(H);
}
