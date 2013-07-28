#include <vector>

#include "common/includes.h"
#include "Hash.h"

#ifndef __MD2__
#define __MD2__

#include "MD2_Const.h"

class MD2 : public Hash{
    private:
        std::string hash;
        void run();

    public:
        MD2(const std::string & str = "");
        std::string hexdigest();
        unsigned int blocksize();
        unsigned int digestsize();
};

#endif
