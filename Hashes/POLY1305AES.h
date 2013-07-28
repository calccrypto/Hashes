#include "common/cryptomath.h"
#include "common/includes.h"
#include "common/integer.h"
#include "Encryptions/AES.h"

#ifndef __POLYAES1305__
#define __POLYAES1305__
class POLY1305AES{
    /*bytes   r[3], r[7], r[11], r[15] have to be less than 16
              r[4], r[8], r[12] have to = 0 mod 4
    */
    private:
        integer r, mod, mod1305;
        std::string nonce, H;

    public:
        POLY1305AES(const std::string & R, const std::string & NONCE);
        void HASH(std::string KEY, std::string MESSAGE);
        std::string hexdigest();
        std::string digest();
};
#endif
