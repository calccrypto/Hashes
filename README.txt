A library of cryptographic hashing algorithms
by Jason Lee @ calccrypto at gmail.com

Please see LICENSE file for license.

IMPORTANT:
    This library was not written for actual use.
    Rather, it was meant for educational purposes,
    so if you choose to use it in a real setting
    where secrecy is required, do so at your own risk.
    People who use this library to learn about the
    algorithms can easily add a few std::couts to
    see the internal data.

Hashes:
    Microsoft's LM Hash
    MD2
    MD4
    MD5
    RIPEMD-128
    RIPEMD-160
    SHA-1
    SHA-224
    SHA-256
    SHA-384
    SHA-512

MACs
    HMAC
    POLY1305AES

Build:
    make

    or

    g++ -std=c++11 main.cpp common/*.cpp Encryptions/*.cpp Hashes/*.cpp -lgmpxx -lgmp

    or some equivalent

You have to provide the main function/file since this is a library,
not a fully functioning program.

Usage:
    Ex:
        SHA1 instance(data to hash in ASCII)

        To get digest:
            instance.digest()
        To get hex string of digest:
            instance.hexdigest()
        To update:
            instance.update(more data)

Notes:
    The GNU Multiple Precision Arithmetic Library (GMP) is needed
    for POly1305-Aes (gmp.org, sudo apt-get install libdev-gmp, or 
    equivalent).

    My Encryptions library is needed for this library. It is included 
    in this project. My integer library is also needed, but only for 
    Encryptions mode-of-operation functions, so it is possible to not 
    need integer.

    The format was inspired by the Python 2.7 hashlib module 

    Hashes.h provides a quick test to check that the algorithms are correct.