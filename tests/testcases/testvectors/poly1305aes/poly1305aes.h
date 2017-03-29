#ifndef __POLY1305AESTESTVECTORS__
#define __POLY1305AESTESTVECTORS__

#include <array>
#include <string>
#include <vector>

// {data, key, r, nonce, MAC}
std::vector <std::array <std::string, 5> > POLY1305AES_TEST_VECTORS = {
    {{"f3f6", "ec074c835580741701425b623235add6", "851fc40c3467ac0be05cc20404f3f700", "fb447350c4e868c52ac3275cf9d4327e", "f4c633c3044fc145f84f335cb81953de"}},
    {{"", "75deaa25c09f208e1dc4ce6b5cad3fbf", "a0f3080000f46400d0c7e9076c834403", "61ee09218d29b0aaed7e154a2c5509cc", "dd3fab2251f11ac759f0887129cc2ee7"}},
    {{"ab0812724a7f1e342742cbed374d94d136c6b8795d45b3819830f2c04491faf0990c62e48b8018b2c3e4a0fa3134cb67fa83e158c994d961c4cb21095c1bf9", "e1a5668a4d5b66a5f68cc5424ed5982d", "12976a08c4426d0ce8a82407c4f48207", "9ae831e743978d3a23527c7128149e3a", "5154ad0d2cb26e01274fc51148491f1b"}},
};

#endif