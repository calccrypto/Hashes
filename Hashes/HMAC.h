/*
HMAC.h
Hash-based message authentication code

Copyright (c) 2013 - 2017 Jason Lee @ calccrypto at gmail.com

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.
*/

#ifndef __HMAC__
#define __HMAC__

#include <iostream>

#include "../Hashes.h"

template <class H = MD5>
class HMAC{
    private:
        std::string h;
        H algo;

    public:
        HMAC(std::string KEY, const std::string & MESSAGE){
            std::size_t blocksize = algo.blocksize() >> 3;
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
        
        std::size_t digestsize() const {return H().digestsize();}
};

#endif
