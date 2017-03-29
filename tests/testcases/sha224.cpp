#include <gtest/gtest.h>

#include "Hashes/SHA224.h"

#include "testvectors/sha/sha224.h"

TEST(SHA224, short_msg) {
    EXPECT_EQ(SHA224().blocksize(),  (std::size_t) 512);
    EXPECT_EQ(SHA224().digestsize(), (std::size_t) 224);
    hash_test <SHA224> (SHA224_SHORT_MSG);
}
