/*
Keccack.h
This is code that is meant to eventually
become a generic implementation of Keccak

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

#ifndef __KECCAK__
#define __KECCAK__

#include <array>
#include <cmath>
#include <functional>
#include <iostream>

#include "../common/cryptomath.h"
#include "../common/includes.h"

#include "Keccak_Const.h"

// KECCAK-p[b, n_r] = base algorithm
// KECCAK-f[b] = KECCAK-p[b, 12 + 2 * l]
class KECCAK_p{
    private:
        unsigned int b,     // width in bits
                     w,     // lane size
                     l,     // log of lane size
                     nr;    // number of rounds

        // should not use bool
        typedef std::array <std::array <uint64_t, 5>, 5> StateArray;

        // Figure 2 in FIPS 202 draft
        // not needed since all coordinates are consistent
        const uint8_t coordinate[5] = {3, 4, 0, 1, 2};

        StateArray s2sa(const std::string & S) const;
        std::string sa2s(const StateArray & A) const;

        StateArray theta(const StateArray & A) const;
        StateArray pirho(const StateArray & A) const;
        // StateArray rho(const StateArray & A);
        // StateArray pi(const StateArray & A);
        StateArray chi(const StateArray & A) const;
        // bool rc(int t);
        StateArray iota(const StateArray & A, const uint64_t rc) const;

        StateArray Rnd(const StateArray & A, const uint64_t rc) const;

        void print(const StateArray & A) const;

    public:
        /*
            w = b / 25
            l = log2(b / 25)
            b: 25 50 100 200 400 800 1600
            w:  1  2   4   8  16  32   64
            l:  0  1   2   3   4   5    6
        */

        KECCAK_p(const unsigned int B, const unsigned int Nr);

        // assumes S is already in binary
        std::string operator()(const std::string & S) const;

        unsigned int get_b() const;
};

// pad10*1
// 5.1
// x is always positive
// unsigned int throws things off
std::string pad101(const int x, const int m);

// Z = SPONGE[f, pad, r]
class SPONGE{
    private:
        KECCAK_p f;
        std::function <std::string(const int, const int)> pad;
        unsigned int r;

    public:
        SPONGE(const KECCAK_p & func,
               std::function <std::string(const int, const int)> pad_func,
               unsigned int rate);

        // M is already in binary form ('\x30' and '\x31' characters only)
        std::string operator()(const std::string & M, const unsigned int d);
};

// KECCAK[c] (M, d) = SPONGE[KECCAK-p[1600, 24], pad10*1, 1600 – c] (M, d)
class KECCAK{
    private:
        SPONGE sponge;

    public:
        KECCAK(const unsigned int c);

        std::string operator()(const std::string & M, const unsigned int d);
};

// SHA3-224(M) = KECCAK[448]  (M || 01, 224)
// SHA3-256(M) = KECCAK[512]  (M || 01, 256)
// SHA3-384(M) = KECCAK[768]  (M || 01, 384)
// SHA3-512(M) = KECCAK[1024] (M || 01, 512)

#endif