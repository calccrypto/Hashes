#include <gtest/gtest.h>

#include "Hashes/RIPEMD160.h"

#include "testvectors/ripemd/ripemd160.h"

TEST(RIPEMD160, testvectors) {
    EXPECT_EQ(RIPEMD160().blocksize(),  512);
    EXPECT_EQ(RIPEMD160().digestsize(), 160);
    hash_test <RIPEMD160> (RIPEMD160_TEST_VECTORS);
}
