#include <gtest/gtest.h>

#include "Hashes/SHA512.h"

#include "testvectors/sha/sha512.h"

TEST(SHA512, short_msg) {
    EXPECT_EQ(SHA512().blocksize(),  (std::size_t) 1024);
    EXPECT_EQ(SHA512().digestsize(), (std::size_t)  512);
    hash_test <SHA512> (SHA512_SHORT_MSG);
}


