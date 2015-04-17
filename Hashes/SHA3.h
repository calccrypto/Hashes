/*
SHA3.h
This implementation only works for SHA3 since it uses
64 bit unsigned ints as lanes instead of individual bits.

Copyright (c) 2013 Jason Lee

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
#include "Hash.h"

#include "Keccak_Const.h"

// KECCAK-p[b, n_r] = base algorithm
// KECCAK-f[b] = KECCAK-p[b, 12 + 2 * l]
class KECCAK_p {
    private:
        unsigned int b,     // width in bits
                     w,     // lane size
                     l,     // log of lane size
                     nr;    // number of rounds

        typedef std::array <std::array <uint64_t, 5>, 5> StateArray;

        StateArray s2sa(const std::string & S) const;
        std::string sa2s(const StateArray & A) const;

        StateArray theta(const StateArray & A) const;
        StateArray pirho(const StateArray & A) const;
        StateArray chi(const StateArray & A) const;
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

// //////////////////////////////////////////////////////////////////////////////////////////
// Dedicated SHA-3 implementation
template <const unsigned int d>
class SHA3 : public Hash{
    private:
        std::string state;
        std::string stack;

        KECCAK_p f;
        int r;

        // absorb data into given state
        void absorb(std::string & S, const std::string & P) const;

        // squeeze output data (concatenate results of f)
        std::string squeeze(std::string & S) const;

    public:
        SHA3();
        SHA3(const std::string & M);

        void update(const std::string & M);
        std::string digest();
        std::string hexdigest();
        unsigned int blocksize() const;
        unsigned int digestsize() const;
};
// //////////////////////////////////////////////////////////////////////////////////////////

#endif