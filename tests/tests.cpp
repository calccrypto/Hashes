#include <iostream>
#include "../Hashes/Hashes.h"

int main(){
    std::cout << "\n\n"
              << (validate_all_hashes(std::cout)?std::string("Passed"):std::string("Failed"))
              << std::endl;
    return 0;
}