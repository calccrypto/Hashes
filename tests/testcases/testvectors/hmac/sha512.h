#ifndef __HMACSHA512TESTVECTORS__
#define __HMACSHA512TESTVECTORS__

#include "../keydatadigest.h"

// Test vectors from somewhere

static const std::vector <KeyDataDigest> HMAC_SHA512_TEST_VECTORS = {
    std::make_tuple("", "", "b936cee86c9f87aa5d3c6f2e84cb5a4239a5fe50480a6ec66b70ab5b1f4ac6730c6c515421b327ec1d69402e53dfb49ad7381eb067b338fd7b0cb22247225d47"),
    std::make_tuple(hexlify("key"), QUICKFOXLAZYDOG, "b42af09057bac1e2d41708e48a902e09b5ff7f12ab428a4fe86653c73dd248fb82f948a549f7b791a5b41915ee4d1ec3935357e4e2317250d0372afa2ebeeb3a"),
};


#endif