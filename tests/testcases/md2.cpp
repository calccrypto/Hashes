#include <gtest/gtest.h>

#include "Hashes/MD2.h"

#include "testvectors/md/md2.h"

TEST(MD2, testvector) {
    EXPECT_EQ(MD2().blocksize(),  128);
    EXPECT_EQ(MD2().digestsize(), 128);
    hash_test <MD2> (MD2_TEST_VECTORS);
}
