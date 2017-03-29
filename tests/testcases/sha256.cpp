#include <gtest/gtest.h>

#include "Hashes/SHA256.h"

#include "testvectors/sha/sha256.h"

TEST(SHA256, short_msg) {
    EXPECT_EQ(SHA256().blocksize(),  512);
    EXPECT_EQ(SHA256().digestsize(), 256);
    hash_test <SHA256> (SHA256_SHORT_MSG);
}

