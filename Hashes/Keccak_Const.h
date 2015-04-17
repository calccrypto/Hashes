/*
SHA3_const.h
Constant values for MD2

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

#ifndef __KECCAK_CONST__
#define __KECCAK_CONST__

/*
    Rotation offsets
           x = 3   x = 4    x = 0    x = 1    x = 2
    y = 2    25     39         3      10       43
    y = 1    55     20        36      44        6
    y = 0    28     27         0       1       62
    y = 4    56     14        18       2       61
    y = 3    21      8        41      45       15
*/

const uint8_t Keccak_rot[5][5] = {{0,  36,  3, 41, 18},
                                  {1,  44, 10, 45,  2},
                                  {62,  6, 43, 15, 61},
                                  {28, 55, 25, 21, 56},
                                  {27, 20, 39,  8, 14}};

// round constants for iota
const uint64_t Keccak_RC[24] = {0x0000000000000001ULL,
                                0x0000000000008082ULL,
                                0x800000000000808AULL,
                                0x8000000080008000ULL,
                                0x000000000000808BULL,
                                0x0000000080000001ULL,
                                0x8000000080008081ULL,
                                0x8000000000008009ULL,
                                0x000000000000008AULL,
                                0x0000000000000088ULL,
                                0x0000000080008009ULL,
                                0x000000008000000AULL,
                                0x000000008000808BULL,
                                0x800000000000008BULL,
                                0x8000000000008089ULL,
                                0x8000000000008003ULL,
                                0x8000000000008002ULL,
                                0x8000000000000080ULL,
                                0x000000000000800AULL,
                                0x800000008000000AULL,
                                0x8000000080008081ULL,
                                0x8000000000008080ULL,
                                0x0000000080000001ULL,
                                0x8000000080008008ULL};
#endif
