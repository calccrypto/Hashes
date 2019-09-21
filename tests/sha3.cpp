#include <gtest/gtest.h>

#include "Hashes/SHA3.h"

#include "testvectors/sha/sha3.h"

TEST(SHA3, 224) {
    EXPECT_EQ(SHA3 <224> ().blocksize(),  (std::size_t) (1600 - 2 * 224));
    EXPECT_EQ(SHA3 <224> ().digestsize(), (std::size_t) 224);
    hash_test <SHA3 <224> > (SHA3_224_TEST_VECTORS);
}

TEST(SHA3, 256) {
    EXPECT_EQ(SHA3 <256> ().blocksize(),  (std::size_t) (1600 - 2 * 256));
    EXPECT_EQ(SHA3 <256> ().digestsize(), (std::size_t) 256);
    hash_test <SHA3 <256> > (SHA3_256_TEST_VECTORS);
}

TEST(SHA3, 384) {
    EXPECT_EQ(SHA3 <384> ().blocksize(),  (std::size_t) (1600 - 2 * 384));
    EXPECT_EQ(SHA3 <384> ().digestsize(), (std::size_t) 384);
    hash_test <SHA3 <384> > (SHA3_384_TEST_VECTORS);
}

TEST(SHA3, 512) {
    EXPECT_EQ(SHA3 <512> ().blocksize(),  (std::size_t) (1600 - 2 * 512));
    EXPECT_EQ(SHA3 <512> ().digestsize(), (std::size_t) 512);
    hash_test <SHA3 <512> > (SHA3_512_TEST_VECTORS);
}
