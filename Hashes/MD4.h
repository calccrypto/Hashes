#include "common/cryptomath.h"
#include "common/includes.h"
#include "Hash.h"

#ifndef __MD4__
#define __MD4__

#include "MD4_Const.h"

class MD4 : public Hash{
    private:
        uint32_t h0, h1, h2, h3;
        void run();

    public:
        MD4(const std::string & str = "");
        std::string hexdigest();
        unsigned int blocksize();
        unsigned int digestsize();
};


#endif
