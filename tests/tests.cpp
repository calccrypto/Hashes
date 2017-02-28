#include <iostream>
#include "../Hashes.h"

// data is in ASCII, digest is in Hex
template <typename Alg> bool validate_hash(const std::string & data, const std::string & digest, std::ostream & stream = null_out, const std::string & name = "", const unsigned int & linew = 25){
    bool correct = (Alg(data).digest() == unhexlify(digest)); // unhexlify digest just in case the input digest uses uppercase hex digits
    stream << "    " << pad(name + ":", linew - 4, ' ') << (correct?"Passed":"Failed") << std::endl;
    return correct;
}

// key and message are in ASCII, digest is in Hex
template <typename Alg> bool validate_HMAC(const std::string & key, const std::string & message, const std::string & digest, std::ostream & stream = null_out, const std::string & name = "", const unsigned int & linew = 25){
    bool correct = (Alg(key, message).digest() == unhexlify(digest)); // unhexlify digest just in case the input digest uses uppercase hex digits
    stream << "    " << pad(name + ":", linew - 4, ' ') << (correct?"Passed":"Failed") << std::endl;
    return correct;
}

bool validate_all_hashes(std::ostream & stream = null_out, const unsigned int & linew = 25){
    bool all_correct = true, correct;

    // No input == empty string == ""
    stream << "No input:" << std::endl;

    all_correct &= validate_hash <LM>               ("", "aad3b435b51404eeaad3b435b51404ee", stream, "LM");
    all_correct &= validate_hash <MD2>              ("", "8350e5a3e24c153df2275c9f80692773", stream, "MD2");
    all_correct &= validate_hash <MD4>              ("", "31d6cfe0d16ae931b73c59d7e0c089c0", stream, "MD4");
    all_correct &= validate_hash <MD5>              ("", "d41d8cd98f00b204e9800998ecf8427e", stream, "MD5");
    all_correct &= validate_hash <RIPEMD128>        ("", "cdf26213a150dc3ecb610f18f6b38b46", stream, "RIPEMD128");
    all_correct &= validate_hash <RIPEMD160>        ("", "9c1185a5c5e9fc54612808977ee8f548b2258d31", stream, "RIPEMD160");
    all_correct &= validate_hash <SHA1>             ("", "da39a3ee5e6b4b0d3255bfef95601890afd80709", stream, "SHA1");
    all_correct &= validate_hash <SHA224>           ("", "d14a028c2a3a2bc9476102bb288234c415a2b01f828ea62ac5b3e42f", stream, "SHA224");
    all_correct &= validate_hash <SHA256>           ("", "e3b0c44298fc1c149afbf4c8996fb92427ae41e4649b934ca495991b7852b855", stream, "SHA256");
    all_correct &= validate_hash <SHA384>           ("", "38b060a751ac96384cd9327eb1b1e36a21fdb71114be07434c0cc7bf63f6e1da274edebfe76f65fbd51ad2f14898b95b", stream, "SHA384");
    all_correct &= validate_hash <SHA512>           ("", "cf83e1357eefb8bdf1542850d66d8007d620e4050b5715dc83f4a921d36ce9ce47d0d13c5d85f2b0ff8318d2877eec2f63b931bd47417a81a538327af927da3e", stream, "SHA512");
    all_correct &= validate_HMAC <HMAC <MD5> >      ("", "", "74e6f7298a9c2d168935f58c001bad88", stream, "HMAC MD5");
    all_correct &= validate_HMAC <HMAC <SHA1> >     ("", "", "fbdb1d1b18aa6c08324b7d64b71fb76370690e1d", stream, "HMAC SHA1");
    all_correct &= validate_HMAC <HMAC <SHA256> >   ("", "", "b613679a0814d9ec772f95d778c35fc5ff1697c493715653c6c712144292c5ad", stream, "HMAC SHA256");
    all_correct &= validate_HMAC <HMAC <SHA512> >   ("", "", "b936cee86c9f87aa5d3c6f2e84cb5a4239a5fe50480a6ec66b70ab5b1f4ac6730c6c515421b327ec1d69402e53dfb49ad7381eb067b338fd7b0cb22247225d47", stream, "HMAC SHA512");

    std::string data = "The quick brown fox jumps over the lazy dog";
    stream << "\nInput: \"" + data + "\"" << std::endl;

    all_correct &= validate_hash <LM>               (data, "a7b07f9948d8cc7f97c4b0b30cae500f", stream, "LM");
    all_correct &= validate_hash <MD2>              (data, "03d85a0d629d2c442e987525319fc471", stream, "MD2");
    all_correct &= validate_hash <MD4>              (data, "1bee69a46ba811185c194762abaeae90", stream, "MD4");
    all_correct &= validate_hash <MD5>              (data, "9e107d9d372bb6826bd81d3542a419d6", stream, "MD5");
    all_correct &= validate_hash <RIPEMD128>        (data, "3fa9b57f053c053fbe2735b2380db596", stream, "RIPEMD128");
    all_correct &= validate_hash <RIPEMD160>        (data, "37f332f68db77bd9d7edd4969571ad671cf9dd3b", stream, "RIPEMD160");
    all_correct &= validate_hash <SHA1>             (data, "2fd4e1c67a2d28fced849ee1bb76e7391b93eb12", stream, "SHA1");
    all_correct &= validate_hash <SHA224>           (data, "730e109bd7a8a32b1cb9d9a09aa2325d2430587ddbc0c38bad911525", stream, "SHA224");
    all_correct &= validate_hash <SHA256>           (data, "d7a8fbb307d7809469ca9abcb0082e4f8d5651e46d3cdb762d02d0bf37c9e592", stream, "SHA256");
    all_correct &= validate_hash <SHA384>           (data, "ca737f1014a48f4c0b6dd43cb177b0afd9e5169367544c494011e3317dbf9a509cb1e5dc1e85a941bbee3d7f2afbc9b1", stream, "SHA384");
    all_correct &= validate_hash <SHA512>           (data, "07e547d9586f6a73f73fbac0435ed76951218fb7d0c8d788a309d785436bbb642e93a252a954f23912547d1e8a3b5ed6e1bfd7097821233fa0538f3db854fee6", stream, "SHA512");
    all_correct &= validate_HMAC <HMAC <MD5> >      ("key", data, "80070713463e7749b90c2dc24911e275", stream, "HMAC MD5");
    all_correct &= validate_HMAC <HMAC <SHA1> >     ("key", data, "de7c9b85b8b78aa6bc8a7a36f70a90701c9db4d9", stream, "HMAC SHA1");
    all_correct &= validate_HMAC <HMAC <SHA256> >   ("key", data, "f7bc83f430538424b13298e6aa6fb143ef4d59a14946175997479dbc2d1a3cd8", stream, "HMAC SHA256");
    all_correct &= validate_HMAC <HMAC <SHA512> >   ("key", data, "b42af09057bac1e2d41708e48a902e09b5ff7f12ab428a4fe86653c73dd248fb82f948a549f7b791a5b41915ee4d1ec3935357e4e2317250d0372afa2ebeeb3a", stream, "HMAC SHA512");

    stream << "\nSHA-3 (Keccak)" << std::endl;
    // http://www.fishtrap.co.uk/online-sha3/
    data = "The quick brown fox jumps over the lazy dog";
    stream << "\nInput: \"" << data << "\"" << std::endl;
    all_correct &= validate_hash <SHA3 <224> >      (data, "d15dadceaa4d5d7bb3b48f446421d542e08ad8887305e28d58335795", stream, "SHA3-224");
    all_correct &= validate_hash <SHA3 <256> >      (data, "69070dda01975c8c120c3aada1b282394e7f032fa9cf32f4cb2259a0897dfc04", stream, "SHA3-256");
    all_correct &= validate_hash <SHA3 <384> >      (data, "7063465e08a93bce31cd89d2e3ca8f602498696e253592ed26f07bf7e703cf328581e1471a7ba7ab119b1a9ebdf8be41", stream, "SHA3-384");
    all_correct &= validate_hash <SHA3 <512> >      (data, "01dedd5de4ef14642445ba5f5b97c15e47b9ad931326e4b0727cd94cefc44fff23f07bf543139939b49128caf436dc1bdee54fcb24023a08d9403f9b4bf0d450", stream, "SHA3-512");

    // http://www.di-mgt.com.au/sha_testvectors.html
    data = "";
    stream << "\nInput: \"" << data << "\"" << std::endl;
    all_correct &= validate_hash <SHA3 <224> >      (data, "6b4e03423667dbb73b6e15454f0eb1abd4597f9a1b078e3f5b5a6bc7", stream, "SHA3-224");
    all_correct &= validate_hash <SHA3 <256> >      (data, "a7ffc6f8bf1ed76651c14756a061d662f580ff4de43b49fa82d80a4b80f8434a", stream, "SHA3-256");
    all_correct &= validate_hash <SHA3 <384> >      (data, "0c63a75b845e4f7d01107d852e4c2485c51a50aaaa94fc61995e71bbee983a2ac3713831264adb47fb6bd1e058d5f004", stream, "SHA3-384");
    all_correct &= validate_hash <SHA3 <512> >      (data, "a69f73cca23a9ac5c8b567dc185a756e97c982164fe25859e0d1dcc1475c80a615b2123af1f5f94c11e3e9402c3ac558f500199d95b6d3e301758586281dcd26", stream, "SHA3-512");

    data = "abc";
    stream << "\nInput: \"" << data << "\"" << std::endl;
    all_correct &= validate_hash <SHA3 <224> >      (data, "e642824c3f8cf24ad09234ee7d3c766fc9a3a5168d0c94ad73b46fdf", stream, "SHA3-224");
    all_correct &= validate_hash <SHA3 <256> >      (data, "3a985da74fe225b2045c172d6bd390bd855f086e3e9d525b46bfe24511431532", stream, "SHA3-256");
    all_correct &= validate_hash <SHA3 <384> >      (data, "ec01498288516fc926459f58e2c6ad8df9b473cb0fc08c2596da7cf0e49be4b298d88cea927ac7f539f1edf228376d25", stream, "SHA3-384");
    all_correct &= validate_hash <SHA3 <512> >      (data, "b751850b1a57168a5693cd924b6b096e08f621827444f70d884f5d0240d2712e10e116e9192af3c91a7ec57647e3934057340b4cf408d5a56592f8274eec53f0", stream, "SHA3-512");

    data = "abcdbcdecdefdefgefghfghighijhijkijkljklmklmnlmnomnopnopq";
    stream << "\nInput: \"" << data << "\"" << std::endl;
    all_correct &= validate_hash <SHA3 <224> >      (data, "8a24108b154ada21c9fd5574494479ba5c7e7ab76ef264ead0fcce33", stream, "SHA3-224");
    all_correct &= validate_hash <SHA3 <256> >      (data, "41c0dba2a9d6240849100376a8235e2c82e1b9998a999e21db32dd97496d3376", stream, "SHA3-256");
    all_correct &= validate_hash <SHA3 <384> >      (data, "991c665755eb3a4b6bbdfb75c78a492e8c56a22c5c4d7e429bfdbc32b9d4ad5aa04a1f076e62fea19eef51acd0657c22", stream, "SHA3-384");
    all_correct &= validate_hash <SHA3 <512> >      (data, "04a371e84ecfb5b8b77cb48610fca8182dd457ce6f326a0fd3d7ec2f1e91636dee691fbe0c985302ba1b0d8dc78c086346b533b49c030d99a27daf1139d6e75e", stream, "SHA3-512");

    data = "abcdefghbcdefghicdefghijdefghijkefghijklfghijklmghijklmnhijklmnoijklmnopjklmnopqklmnopqrlmnopqrsmnopqrstnopqrstu";
    stream << "\nInput: \"" << data << "\"" << std::endl;
    all_correct &= validate_hash <SHA3 <224> >      (data, "543e6868e1666c1a643630df77367ae5a62a85070a51c14cbf665cbc", stream, "SHA3-224");
    all_correct &= validate_hash <SHA3 <256> >      (data, "916f6061fe879741ca6469b43971dfdb28b1a32dc36cb3254e812be27aad1d18", stream, "SHA3-256");
    all_correct &= validate_hash <SHA3 <384> >      (data, "79407d3b5916b59c3e30b09822974791c313fb9ecc849e406f23592d04f625dc8c709b98b43b3852b337216179aa7fc7", stream, "SHA3-384");
    all_correct &= validate_hash <SHA3 <512> >      (data, "afebb2ef542e6579c50cad06d2e578f9f8dd6881d7dc824d26360feebf18a4fa73e3261122948efcfd492e74e82e2189ed0fb440d187f382270cb455f21dd185", stream, "SHA3-512");

    data = std::string(1000000, 'a');
    stream << "\nInput: One million 'a's" << std::endl;
    all_correct &= validate_hash <SHA3 <224> >      (data, "d69335b93325192e516a912e6d19a15cb51c6ed5c15243e7a7fd653c", stream, "SHA3-224");
    all_correct &= validate_hash <SHA3 <256> >      (data, "5c8875ae474a3634ba4fd55ec85bffd661f32aca75c6d699d0cdcb6c115891c1", stream, "SHA3-256");
    all_correct &= validate_hash <SHA3 <384> >      (data, "eee9e24d78c1855337983451df97c8ad9eedf256c6334f8e948d252d5e0e76847aa0774ddb90a842190d2c558b4b8340", stream, "SHA3-384");
    all_correct &= validate_hash <SHA3 <512> >      (data, "3c3a876da14034ab60627c077bb98f7e120a2a5370212dffb3385a18d4f38859ed311d0a9d5141ce9cc5c66ee689b266a8aa18ace8282a0e0db596c90b0a7b87", stream, "SHA3-512");

    stream << "\nOthers:" << std::endl;

    data = unhexlify("f3f6");
    std::string key = unhexlify("ec074c835580741701425b623235add6");
    std::string r = unhexlify("851fc40c3467ac0be05cc20404f3f700");
    std::string nonce = unhexlify("fb447350c4e868c52ac3275cf9d4327e");
    POLY1305AES p1(r, nonce);
    p1.HASH(key,data);
    correct = (p1.hexdigest() == "f4c633c3044fc145f84f335cb81953de");
    stream <<  "    POLY1305AES TEST 1:  " << (correct?"Passed":"Failed") << std::endl;
    all_correct &= correct;

    data = unhexlify("");
    key = unhexlify("75deaa25c09f208e1dc4ce6b5cad3fbf");
    r = unhexlify("a0f3080000f46400d0c7e9076c834403");
    nonce = unhexlify("61ee09218d29b0aaed7e154a2c5509cc");
    POLY1305AES p2(r, nonce);
    p2.HASH(key, data);
    correct = (p2.hexdigest() == "dd3fab2251f11ac759f0887129cc2ee7");
    stream << "    POLY1305AES TEST 2:  " << (correct?"Passed":"Failed") << std::endl;
    all_correct &= correct;

    data = unhexlify("ab0812724a7f1e342742cbed374d94d136c6b8795d45b3819830f2c04491faf0990c62e48b8018b2c3e4a0fa3134cb67fa83e158c994d961c4cb21095c1bf9");
    key = unhexlify("e1a5668a4d5b66a5f68cc5424ed5982d");
    r = unhexlify("12976a08c4426d0ce8a82407c4f48207");
    nonce = unhexlify("9ae831e743978d3a23527c7128149e3a");
    POLY1305AES p3(r, nonce);
    p3.HASH(key, data);
    correct = (p3.hexdigest() == "5154ad0d2cb26e01274fc51148491f1b");
    stream << "    POLY1305AES TEST 3:  " << (correct?"Passed":"Failed") << std::endl;
    all_correct &= correct;

    return all_correct;
}

int main(){
    std::cout << "\n\n"
              << (validate_all_hashes(std::cout)?std::string("Passed"):std::string("Failed"))
              << std::endl;
    return 0;
}