/*
SHA3.h
This implementation only works for SHA3 since it uses
64 bit unsigned ints as lanes instead of individual bits.

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

#ifndef __SHA3__
#define __SHA3__

#include <array>
#include <cmath>
#include <functional>
#include <iostream>

#include "../common/cryptomath.h"
#include "../common/includes.h"
#include "HashAlg.h"

#include "Keccak_Const.h"

template <const unsigned int d>
class SHA3 : public HashAlg{
    private:
        const unsigned int b,     // width in bits (1600)
                           w,     // lane size (64)
                           l,     // log of lane size (6)
                           nr;    // number of rounds (24)

        typedef std::array <std::array <uint64_t, 5>, 5> StateArray;

        std::string state;
        std::string stack;
        int r;                    // rate (1600 - 2 * d)

        // Keccak Functions /////////////////
        StateArray s2sa(const std::string & S) const;
        std::string sa2s(const StateArray & A) const;

        StateArray theta(const StateArray & A) const;
        StateArray pirho(const StateArray & A) const;
        StateArray chi(const StateArray & A) const;
        StateArray iota(const StateArray & A, const uint64_t rc) const;

        std::string f(const std::string & S) const;
        // //////////////////////////////////

        // Sponge Functions /////////////////
        // absorb data into given state
        void absorb(std::string & S, const std::string & P) const;

        // squeeze output data (concatenate results of f)
        std::string squeeze(std::string & S) const;
        // //////////////////////////////////

    public:
        SHA3();
        SHA3(const std::string & M);

        void update(const std::string & M);
        std::string digest();
        std::string hexdigest();
        unsigned int blocksize() const;
        unsigned int digestsize() const;
};

#endif