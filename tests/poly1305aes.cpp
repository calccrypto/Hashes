#include <gtest/gtest.h>

#include "Hashes/POLY1305AES.h"

#include "testvectors/poly1305aes/poly1305aes.h"

TEST(POLY1305AES, testvectors) {
    for(std::array <std::string, 5> const & tv : POLY1305AES_TEST_VECTORS){
        POLY1305AES p(unhexlify(tv[2]), unhexlify(tv[3]));
        p.HASH(unhexlify(tv[1]), unhexlify(tv[0]));
        EXPECT_EQ(p.digest(), unhexlify(tv[4]));
    }
}
