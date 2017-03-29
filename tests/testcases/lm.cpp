#include <gtest/gtest.h>

#include "Hashes/LM.h"

#include "testvectors/lm/lm.h"

TEST(LM, testvector) {
    EXPECT_EQ(LM().digestsize(), 128);
    hash_test <LM> (LM_TEST_VECTORS);
}
