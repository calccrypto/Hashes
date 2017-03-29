#ifndef __MD2TESTVECTORS__
#define __MD2TESTVECTORS__

#include "../datadigest.h"

// Test vectors from <http://www.nco.ncep.noaa.gov/pmb/codes/nwprod/decoders/decod_shared/lib/polarssl/tests/suites/test_suite_md.data>

static const std::vector <DataDigest> MD2_TEST_VECTORS = {
    std::make_tuple("", "8350e5a3e24c153df2275c9f80692773"),
    std::make_tuple(hexlify("a"), "32ec01ec4a6dac72c0ab96fb34c0b5d1"),
    std::make_tuple(hexlify("abc"), "da853b0d3f88d99b30283a69e6ded6bb"),
    std::make_tuple(hexlify("message digest"), "ab4f496bfb2a530b219ff33031fe06b0"),
    std::make_tuple(hexlify("abcdefghijklmnopqrstuvwxyz"), "4e8ddff3650292ab5a4108c3aa47940b"),
    std::make_tuple(hexlify("ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789"), "da33def2a42df13975352846c30338cd"),
    std::make_tuple(hexlify("12345678901234567890123456789012345678901234567890123456789012345678901234567890"), "d5976f79d83d3a0dc9806c3c66f3efd8"),
    std::make_tuple(QUICKFOXLAZYDOG, "03d85a0d629d2c442e987525319fc471"),
};

#endif // __MD2TESTVECTORS__
