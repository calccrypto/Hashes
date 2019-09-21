#include <gtest/gtest.h>

#include "Hashes/LM.h"

#include "testvectors/lm/lm.h"

TEST(LM, testvectors) {
    EXPECT_EQ(LM().digestsize(), (std::size_t) 128);
    hash_test <LM> (LM_TEST_VECTORS);
}
