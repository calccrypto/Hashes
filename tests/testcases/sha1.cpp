#include <gtest/gtest.h>

#include "Hashes/SHA1.h"

#include "testvectors/sha/sha1.h"

TEST(SHA1, short_msg) {
    EXPECT_EQ(SHA1().blocksize(),  (std::size_t) 512);
    EXPECT_EQ(SHA1().digestsize(), (std::size_t) 160);
    hash_test <SHA1> (SHA1_SHORT_MSG);
}
