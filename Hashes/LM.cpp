#include "LM.h"

LM::LM(const std::string & key){
    run(key);
}

void LM::run(std::string key){
    for(unsigned int x = 0; x < std::min(key.size(), (size_t) 14); x++){
        key[x] = toupper(key[x]);
    }
    while (key.size() < 14){
        key += zero;
    }
    std::string left = "", right = "";
    for(uint8_t x = 0; x < 7; x++){
        left += makebin((uint8_t) key[x], 8);
        right += makebin((uint8_t) key[x + 7], 8);
    }
    for(uint8_t x = 0; x < 8; x++){
        left += left.substr(7 * x, 7) + "0";
        right += right.substr(7 * x, 7) + "0";
    }
    left = unhexlify(bintohex(left.substr(56, 64)));
    right = unhexlify(bintohex(right.substr(56, 64)));
    data = DES(left).encrypt("\x4b\x47\x53\x21\x40\x23\x24\x25") + DES(right).encrypt("\x4b\x47\x53\x21\x40\x23\x24\x25");
}

std::string LM::hexdigest(){
    return hexlify(data);
}

std::string LM::digest(){
    return data;
}
