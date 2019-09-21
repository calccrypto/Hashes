/*
keydatadigest.h

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

#ifndef __KEY_DATA_DIGEST__
#define __KEY_DATA_DIGEST__

#include <string>
#include <type_traits>
#include <utility>
#include <vector>

#include <gtest/gtest.h>

#include "common/includes.h"
#include "Hashes/HashAlg.h"
#include "Hashes/HMAC.h"

#include "datadigest.h"

// all input is in hex

typedef std::tuple <std::string, std::string, std::string> KeyDataDigest;

template <typename Hash>
void hmac_test(const std::vector <KeyDataDigest> & test_vectors){
    static_assert(std::is_base_of <HashAlg, Hash>::value, "Error: Algorithm type should be a hash algorithm.");

    for(KeyDataDigest const & kdd : test_vectors){
        std::string key, data, digest;
        std::tie(key, data, digest) = kdd;

        // unhexlify digest just in case the input digest uses uppercase hex digits
        EXPECT_EQ(HMAC <Hash> (unhexlify(key), unhexlify(data)).digest(), unhexlify(digest));
    }
}

#endif