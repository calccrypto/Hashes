#include <gtest/gtest.h>

#include "Hashes/KECCAK.h"

#include "testvectors/sha/sha3.h"

TEST(Keccak, 224) {
    hash_test <Keccak <224> > (SHA3_224_TEST_VECTORS);
}

TEST(Keccak, 256) {
    hash_test <Keccak <256> > (SHA3_256_TEST_VECTORS);
}

TEST(Keccak, 384) {
    hash_test <Keccak <384> > (SHA3_384_TEST_VECTORS);
}

TEST(Keccak, 512) {
    hash_test <Keccak <512> > (SHA3_512_TEST_VECTORS);
}
