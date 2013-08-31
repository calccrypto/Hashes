A library of cryptographic hashing alogorithms
by Jason Lee @ calccrypto at gmail.com

Please see LICENSE file for license.

IMPORTANT:
    This library was not written for actual use.
    Rather, it was meant for educational purposes,
    so if you choose to use it in a real setting
    where secrecy is requied, do so at your own risk.
    People who use this library to learn about the
    algorithms can easily add a few std::couts to
    see the internal data.

Hashes:
    Microsofts' LM Hash
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
    My encryptions library is also needed. Download at:
    https://github.com/calccrypto/Encryptions

    Just copy the Encryptions folder into where the Hashes
    folder is:

        Hashes/common
        Hashes/Encryptions
        Hashes/Hashes


	make (creates the object files only)

	or

	g++ -std=c++11 main.cpp common/*.cpp Encryptions/*.cpp Hashes/*.cpp

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
    The format was inspired by the Python 2.7 hashlib module

    I have no idea how the unhashed data is stored in other
    implementations so each instance just holds a copy of all
    the data inputted into it and rehashes everything every time.