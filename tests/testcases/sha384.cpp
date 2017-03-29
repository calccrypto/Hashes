#include <gtest/gtest.h>

#include "Hashes/SHA384.h"

#include "testvectors/sha/sha384.h"

TEST(SHA384, short_msg) {
    EXPECT_EQ(SHA384().blocksize(),  (std::size_t) 1024);
    EXPECT_EQ(SHA384().digestsize(), (std::size_t)  384);
    hash_test <SHA384> (SHA384_SHORT_MSG);
}


