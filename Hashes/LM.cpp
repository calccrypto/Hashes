#include "./LM.h"

void LM::update(std::string KEY){
    for(unsigned int x = 0; x < KEY.size(); x++){
        KEY[x] = toupper(KEY[x]);
    }
    while (KEY.size() < 14){
        KEY += zero;
    }
    std::string left = "", right = "";
    for(uint8_t x = 0; x < 7; x++){
        left += makebin((uint8_t) KEY[x], 8);
        right += makebin((uint8_t) KEY[x + 7], 8);
    }
    for(uint8_t x = 0; x < 8; x++){
        left += left.substr(7 * x, 7) + "0";
        right += right.substr(7 * x, 7) + "0";
    }
    left = left.substr(56, 64);
    right = right.substr(56, 64);
    left = unhexlify(bintohex(left));
    right = unhexlify(bintohex(right));
    hash = DES(left).encrypt("\x4b\x47\x53\x21\x40\x23\x24\x25") + DES(right).encrypt("\x4b\x47\x53\x21\x40\x23\x24\x25");
}

LM::LM(const std::string & KEY){
    update(KEY);
}

std::string LM::hexdigest(){
    return hexlify(hash);
}

std::string LM::digest(){
    return hash;
}
