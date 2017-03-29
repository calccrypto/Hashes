#include <gtest/gtest.h>

#include "Hashes/HMAC.h"
#include "Hashes/MD5.h"
#include "Hashes/SHA1.h"
#include "Hashes/SHA256.h"
#include "Hashes/SHA512.h"

#include "testvectors/hmac/MD5.h"
#include "testvectors/hmac/SHA1.h"
#include "testvectors/hmac/SHA256.h"
#include "testvectors/hmac/SHA512.h"

TEST(HMAC, MD5) {
    hmac_test <MD5> (HMAC_MD5_TEST_VECTORS);
}

TEST(HMAC, SHA1) {
    hmac_test <SHA1> (HMAC_SHA1_TEST_VECTORS);
}

TEST(HMAC, SHA256) {
    hmac_test <SHA256> (HMAC_SHA256_TEST_VECTORS);
}

TEST(HMAC, SHA512) {
    hmac_test <SHA512> (HMAC_SHA512_TEST_VECTORS);
}
