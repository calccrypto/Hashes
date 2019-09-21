#include <gtest/gtest.h>

#include "Hashes/RIPEMD128.h"

#include "testvectors/ripemd/ripemd128.h"

TEST(RIPEMD128, testvectors) {
    EXPECT_EQ(RIPEMD128().blocksize(),  (std::size_t) 512);
    EXPECT_EQ(RIPEMD128().digestsize(), (std::size_t) 128);
    hash_test <RIPEMD128> (RIPEMD128_TEST_VECTORS);
}
