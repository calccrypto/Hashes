#ifndef __LMTESTVECTORS__
#define __LMTESTVECTORS__

#include "../datadigest.h"

// Test vectors from somewhere

static const std::vector <DataDigest> LM_TEST_VECTORS = {
    std::make_tuple("", "aad3b435b51404eeaad3b435b51404ee"),
    std::make_tuple(QUICKFOXLAZYDOG, "a7b07f9948d8cc7f97c4b0b30cae500f"),
};

#endif // __LMTESTVECTORS__
