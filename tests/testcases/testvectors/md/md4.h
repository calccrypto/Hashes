#ifndef __MD4TESTVECTORS__
#define __MD4TESTVECTORS__

#include "../datadigest.h"

// Test vectors from <http://www.nco.ncep.noaa.gov/pmb/codes/nwprod/decoders/decod_shared/lib/polarssl/tests/suites/test_suite_md.data>

static const std::vector <DataDigest> MD4_TEST_VECTORS = {
    std::make_tuple("", "31d6cfe0d16ae931b73c59d7e0c089c0"),
    std::make_tuple(hexlify("a"), "bde52cb31de33e46245e05fbdbd6fb24"),
    std::make_tuple(hexlify("abc"), "a448017aaf21d8525fc10ae87aa6729d"),
    std::make_tuple(hexlify("message digest"), "d9130a8164549fe818874806e1c7014b"),
    std::make_tuple(hexlify("abcdefghijklmnopqrstuvwxyz"), "d79e1c308aa5bbcdeea8ed63df412da9"),
    std::make_tuple(hexlify("ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789"), "043f8582f241db351ce627e153e7f0e4"),
    std::make_tuple(hexlify("12345678901234567890123456789012345678901234567890123456789012345678901234567890"), "e33b4ddc9c38f2199c3e7b164fcc0536"),
    std::make_tuple(QUICKFOXLAZYDOG, "1bee69a46ba811185c194762abaeae90"),
};

#endif // __MD4TESTVECTORS__
