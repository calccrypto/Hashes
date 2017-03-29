#include <gtest/gtest.h>

#include "Hashes/KECCAK.h"

#include "testvectors/keccak/keccak.h"

TEST(KECCAK, 224) {
    for(DataDigest const & dd : KECCAK_224_TEST_VECTORS){
        std::string data, digest;
        std::tie(data, digest) = dd;

        // unhexlify digest just in case the input digest uses uppercase hex digits
        EXPECT_EQ(unbinify(KECCAK(448)(data, 224)), unhexlify(digest));
    }
}

TEST(KECCAK, 256) {
    for(DataDigest const & dd : KECCAK_256_TEST_VECTORS){
        std::string data, digest;
        std::tie(data, digest) = dd;

        // unhexlify digest just in case the input digest uses uppercase hex digits
        EXPECT_EQ(unbinify(KECCAK(512)(data, 256)), unhexlify(digest));
    }}

TEST(KECCAK, 384) {
    for(DataDigest const & dd : KECCAK_384_TEST_VECTORS){
        std::string data, digest;
        std::tie(data, digest) = dd;

        // unhexlify digest just in case the input digest uses uppercase hex digits
        EXPECT_EQ(unbinify(KECCAK(768)(data, 384)), unhexlify(digest));
    }}

TEST(KECCAK, 512) {
    for(DataDigest const & dd : KECCAK_512_TEST_VECTORS){
        std::string data, digest;
        std::tie(data, digest) = dd;

        // unhexlify digest just in case the input digest uses uppercase hex digits
        EXPECT_EQ(unbinify(KECCAK(1024)(data, 512)), unhexlify(digest));
    }}
