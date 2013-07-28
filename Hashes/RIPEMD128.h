#include "common/cryptomath.h"
#include "common/includes.h"
#include "Hash.h"

#ifndef __RIPEMD128__
#define __RIPEMD128__

#include "RIPEMD_Const.h"
#include "RIPEMD128_Const.h"

class RIPEMD128 : public Hash{
    private:
        uint32_t h0, h1, h2, h3;
        uint32_t F(const uint32_t & x, const uint32_t & y, const uint32_t & z, const uint8_t round);

        void run();

    public:
        RIPEMD128(const std::string & str = "");
        std::string hexdigest();
        unsigned int blocksize();
        unsigned int digestsize();
};
#endif
