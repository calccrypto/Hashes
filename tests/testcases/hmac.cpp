#include <gtest/gtest.h>

#include "Hashes/HMAC.h"
#include "Hashes/MD5.h"
#include "Hashes/SHA1.h"
#include "Hashes/SHA256.h"
#include "Hashes/SHA512.h"

#include "testvectors/hmac/md5.h"
#include "testvectors/hmac/sha1.h"
#include "testvectors/hmac/sha256.h"
#include "testvectors/hmac/sha512.h"

TEST(HMAC, MD5) {
    EXPECT_EQ(HMAC <MD5> ("", "").digestsize(), MD5().digestsize());
    hmac_test <MD5> (HMAC_MD5_TEST_VECTORS);
}

TEST(HMAC, SHA1) {
    EXPECT_EQ(HMAC <SHA1> ("", "").digestsize(), SHA1().digestsize());
    hmac_test <SHA1> (HMAC_SHA1_TEST_VECTORS);
}

TEST(HMAC, SHA256) {
    EXPECT_EQ(HMAC <SHA256> ("", "").digestsize(), SHA256().digestsize());
    hmac_test <SHA256> (HMAC_SHA256_TEST_VECTORS);
}

TEST(HMAC, SHA512) {
    EXPECT_EQ(HMAC <SHA512> ("", "").digestsize(), SHA512().digestsize());
    hmac_test <SHA512> (HMAC_SHA512_TEST_VECTORS);
}
