#ifndef __HMACSHA1TESTVECTORS__
#define __HMACSHA1TESTVECTORS__

#include "../keydatadigest.h"

// Test vectors from somewhere

static const std::vector <KeyDataDigest> HMAC_SHA1_TEST_VECTORS = {
    std::make_tuple("", "", "fbdb1d1b18aa6c08324b7d64b71fb76370690e1d"),
    std::make_tuple(hexlify("key"), QUICKFOXLAZYDOG, "de7c9b85b8b78aa6bc8a7a36f70a90701c9db4d9"),
};


#endif