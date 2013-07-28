#include "common/includes.h"
#include "Encryptions/DES.h"

#ifndef __LM__
#define __LM__
class LM{
    private:
        std::string hash;

        void update(std::string KEY);

    public:
        LM(const std::string & KEY = "");
        std::string hexdigest();
        std::string digest();
};
#endif
