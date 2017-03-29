#ifndef __SHA3TESTVECTORS__
#define __SHA3TESTVECTORS__

#include "../datadigest.h"

// Test vectors from <http://www.fishtrap.co.uk/online-sha3/> and <http://www.di-mgt.com.au/sha_testvectors.html>

static const std::string SHA3_EMPTY     = "";
static const std::string SHA3_ABC       = hexlify("abc");
static const std::string SHA3_ABC2      = hexlify("abcdbcdecdefdefgefghfghighijhijkijkljklmklmnlmnomnopnopq");
static const std::string SHA3_ABC3      = hexlify("abcdefghbcdefghicdefghijdefghijkefghijklfghijklmghijklmnhijklmnoijklmnopjklmnopqklmnopqrlmnopqrsmnopqrstnopqrstu");
static const std::string SHA3_MILLION_A = hexlify(std::string(1000000, 'a'));

static const std::vector <DataDigest> SHA3_224_TEST_VECTORS = {
    std::make_tuple(SHA3_EMPTY,      "6b4e03423667dbb73b6e15454f0eb1abd4597f9a1b078e3f5b5a6bc7"),
    std::make_tuple(SHA3_ABC,        "e642824c3f8cf24ad09234ee7d3c766fc9a3a5168d0c94ad73b46fdf"),
    std::make_tuple(SHA3_ABC2,       "8a24108b154ada21c9fd5574494479ba5c7e7ab76ef264ead0fcce33"),
    std::make_tuple(SHA3_ABC3,       "543e6868e1666c1a643630df77367ae5a62a85070a51c14cbf665cbc"),
    std::make_tuple(SHA3_MILLION_A,  "d69335b93325192e516a912e6d19a15cb51c6ed5c15243e7a7fd653c"),
    std::make_tuple(QUICKFOXLAZYDOG, "d15dadceaa4d5d7bb3b48f446421d542e08ad8887305e28d58335795"),
};

static const std::vector <DataDigest> SHA3_256_TEST_VECTORS = {
    std::make_tuple(SHA3_EMPTY,      "a7ffc6f8bf1ed76651c14756a061d662f580ff4de43b49fa82d80a4b80f8434a"),
    std::make_tuple(SHA3_ABC,        "3a985da74fe225b2045c172d6bd390bd855f086e3e9d525b46bfe24511431532"),
    std::make_tuple(SHA3_ABC2,       "41c0dba2a9d6240849100376a8235e2c82e1b9998a999e21db32dd97496d3376"),
    std::make_tuple(SHA3_ABC3,       "916f6061fe879741ca6469b43971dfdb28b1a32dc36cb3254e812be27aad1d18"),
    std::make_tuple(SHA3_MILLION_A,  "5c8875ae474a3634ba4fd55ec85bffd661f32aca75c6d699d0cdcb6c115891c1"),
    std::make_tuple(QUICKFOXLAZYDOG, "69070dda01975c8c120c3aada1b282394e7f032fa9cf32f4cb2259a0897dfc04"),
};

static const std::vector <DataDigest> SHA3_384_TEST_VECTORS = {
    std::make_tuple(SHA3_EMPTY,      "0c63a75b845e4f7d01107d852e4c2485c51a50aaaa94fc61995e71bbee983a2ac3713831264adb47fb6bd1e058d5f004"),
    std::make_tuple(SHA3_ABC,        "ec01498288516fc926459f58e2c6ad8df9b473cb0fc08c2596da7cf0e49be4b298d88cea927ac7f539f1edf228376d25"),
    std::make_tuple(SHA3_ABC2,       "991c665755eb3a4b6bbdfb75c78a492e8c56a22c5c4d7e429bfdbc32b9d4ad5aa04a1f076e62fea19eef51acd0657c22"),
    std::make_tuple(SHA3_ABC3,       "79407d3b5916b59c3e30b09822974791c313fb9ecc849e406f23592d04f625dc8c709b98b43b3852b337216179aa7fc7"),
    std::make_tuple(SHA3_MILLION_A,  "eee9e24d78c1855337983451df97c8ad9eedf256c6334f8e948d252d5e0e76847aa0774ddb90a842190d2c558b4b8340"),
    std::make_tuple(QUICKFOXLAZYDOG, "7063465e08a93bce31cd89d2e3ca8f602498696e253592ed26f07bf7e703cf328581e1471a7ba7ab119b1a9ebdf8be41"),
};

static const std::vector <DataDigest> SHA3_512_TEST_VECTORS = {
    std::make_tuple(SHA3_EMPTY,      "a69f73cca23a9ac5c8b567dc185a756e97c982164fe25859e0d1dcc1475c80a615b2123af1f5f94c11e3e9402c3ac558f500199d95b6d3e301758586281dcd26"),
    std::make_tuple(SHA3_ABC,        "b751850b1a57168a5693cd924b6b096e08f621827444f70d884f5d0240d2712e10e116e9192af3c91a7ec57647e3934057340b4cf408d5a56592f8274eec53f0"),
    std::make_tuple(SHA3_ABC2,       "04a371e84ecfb5b8b77cb48610fca8182dd457ce6f326a0fd3d7ec2f1e91636dee691fbe0c985302ba1b0d8dc78c086346b533b49c030d99a27daf1139d6e75e"),
    std::make_tuple(SHA3_ABC3,       "afebb2ef542e6579c50cad06d2e578f9f8dd6881d7dc824d26360feebf18a4fa73e3261122948efcfd492e74e82e2189ed0fb440d187f382270cb455f21dd185"),
    std::make_tuple(SHA3_MILLION_A,  "3c3a876da14034ab60627c077bb98f7e120a2a5370212dffb3385a18d4f38859ed311d0a9d5141ce9cc5c66ee689b266a8aa18ace8282a0e0db596c90b0a7b87"),
    std::make_tuple(QUICKFOXLAZYDOG, "01dedd5de4ef14642445ba5f5b97c15e47b9ad931326e4b0727cd94cefc44fff23f07bf543139939b49128caf436dc1bdee54fcb24023a08d9403f9b4bf0d450"),
};

#endif