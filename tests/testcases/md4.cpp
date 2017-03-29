#include <gtest/gtest.h>

#include "Hashes/MD4.h"

#include "testvectors/md/md4.h"

TEST(MD4, testvector) {
    EXPECT_EQ(MD4().blocksize(),  512);
    EXPECT_EQ(MD4().digestsize(), 128);
    hash_test <MD4> (MD4_TEST_VECTORS);
}
