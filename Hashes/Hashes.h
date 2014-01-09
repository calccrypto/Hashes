/*
Hashes.h
File to include to make all hash algorithms 
available. Also provides a testing function

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

#ifndef HASHES_H
#define HASHES_H

#include "../common/cryptomath.h"
#include "../common/includes.h"
#include "Hash.h"

#include "LM.h"
#include "MD2.h"
#include "MD4.h"
#include "MD5.h"
#include "RIPEMD128.h"
#include "RIPEMD160.h"
#include "SHA1.h"
#include "SHA256.h"
#include "SHA224.h"
#include "SHA512.h"
#include "SHA384.h"

#include "HMAC.h"
#include "POLY1305AES.h"

bool validate_hash(std::ostream & stream = null_out);

#endif
