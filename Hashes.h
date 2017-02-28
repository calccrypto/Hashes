/*
Hashes.h
File to include to make all hash algorithms
available. Also provides a testing function

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

#ifndef HASHES_H
#define HASHES_H

#include "common/cryptomath.h"
#include "common/includes.h"
#include "Hashes/Hash.h"

// #include "Keccak.h"
#include "Hashes/LM.h"
#include "Hashes/MD2.h"
#include "Hashes/MD4.h"
#include "Hashes/MD5.h"
#include "Hashes/RIPEMD128.h"
#include "Hashes/RIPEMD160.h"
#include "Hashes/SHA1.h"
#include "Hashes/SHA256.h"
#include "Hashes/SHA224.h"
#include "Hashes/SHA512.h"
#include "Hashes/SHA384.h"
#include "Hashes/SHA3.h"

#include "Hashes/HMAC.h"
#include "Hashes/POLY1305AES.h"

#endif
