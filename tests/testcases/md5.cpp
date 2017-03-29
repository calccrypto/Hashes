#include <gtest/gtest.h>

#include "Hashes/MD5.h"

#include "testvectors/md/md5.h"

TEST(MD5, testvectors) {
    EXPECT_EQ(MD5().blocksize(),  512);
    EXPECT_EQ(MD5().digestsize(), 128);
    hash_test <MD5> (MD5_TEST_VECTORS);
}
