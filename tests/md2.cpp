#include <gtest/gtest.h>

#include "Hashes/MD2.h"

#include "testvectors/md/md2.h"

TEST(MD2, testvectors) {
    EXPECT_EQ(MD2().blocksize(),  (std::size_t) 128);
    EXPECT_EQ(MD2().digestsize(), (std::size_t) 128);
    hash_test <MD2> (MD2_TEST_VECTORS);
}
