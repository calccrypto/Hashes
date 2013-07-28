#include <iostream>

#ifndef __HMAC__
#define __HMAC__
template <class H = MD5>
class HMAC{
    private:
        std::string h;
        H algo;

    public:
        HMAC(std::string KEY, const std::string & MESSAGE){
            unsigned int blocksize = algo.blocksize() >> 3;
            if (KEY.size() > blocksize)
                KEY = H(KEY).digest();
            while (KEY.size() < blocksize)
                KEY += zero;
            std::string opad = "", ipad = "";
            for(unsigned int x = 0; x < KEY.size(); x++){
                opad += std::string(1, 0x5c ^ KEY[x]);
                ipad += std::string(1, 0x36 ^ KEY[x]);
            }
            h = H(opad + H(ipad + MESSAGE).digest()).digest();
        }

        std::string digest(){return h;}

        std::string hexdigest(){return hexlify(h);}
};

#endif
