#ifndef __HMACMD5TESTVECTORS__
#define __HMACMD5TESTVECTORS__

#include "../keydatadigest.h"

// Test vectors from somewhere

static const std::vector <KeyDataDigest> HMAC_MD5_TEST_VECTORS = {
    std::make_tuple("", "", "74e6f7298a9c2d168935f58c001bad88"),
    std::make_tuple(hexlify("key"), QUICKFOXLAZYDOG, "80070713463e7749b90c2dc24911e275"),
};


#endif