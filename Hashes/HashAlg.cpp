#include "MerkleDamgard.h"

HashAlg::HashAlg(){}

HashAlg::~HashAlg(){}

std::string HashAlg::digest(){
    return unhexlify(hexdigest());
}
