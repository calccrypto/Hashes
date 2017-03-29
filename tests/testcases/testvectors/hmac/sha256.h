#ifndef __HMACSHA256TESTVECTORS__
#define __HMACSHA256TESTVECTORS__

#include "../keydatadigest.h"

// Test vectors from somewhere

static const std::vector <KeyDataDigest> HMAC_SHA256_TEST_VECTORS = {
    std::make_tuple("", "", "b613679a0814d9ec772f95d778c35fc5ff1697c493715653c6c712144292c5ad"),
    std::make_tuple(hexlify("key"), QUICKFOXLAZYDOG, "f7bc83f430538424b13298e6aa6fb143ef4d59a14946175997479dbc2d1a3cd8"),
};


#endif