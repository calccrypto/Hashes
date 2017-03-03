/*
POLY1305AES.h
The Poly1305-AES algorithm
http://cr.yp.to/mac.html

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

#ifndef __POLYAES1305__
#define __POLYAES1305__

#include "../common/cryptomath.h"
#include "../common/includes.h"
#include "../Encryptions/AES.h"

#include <gmpxx.h>

class POLY1305AES {
    /*bytes   r[3], r[7], r[11], r[15] have to be less than 16
              r[4], r[8], r[12] have to = 0 mod 4
    */
    private:
        mpz_class r, mod, mod1305;
        std::string nonce, H;

    public:
        POLY1305AES(const std::string & R, const std::string & NONCE);
        void HASH(const std::string & key, const std::string & message);
        std::string hexdigest();
        std::string digest();
};

#endif
