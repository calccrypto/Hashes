/*
MD2.h
RSA Data Security, Inc. MD2 Message Digest Algorithm

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

#ifndef __MD2__
#define __MD2__

#include <vector>

#include "../common/includes.h"
#include "MerkleDamgard.h"

#include "MD2_Const.h"

class MD2 : public MerkleDamgard{
    private:
        uint8_t L = 0;
        std::string C;
        std::string X;

        void checksum(std::string & c, const std::string & data);
        void process(std::string & x, const std::string & data);
        void run();

    public:
        MD2();
        MD2(const std::string & data);
        void update(const std::string & data = "");
        std::string hexdigest();
        unsigned int blocksize() const;
        unsigned int digestsize() const;
};

#endif
