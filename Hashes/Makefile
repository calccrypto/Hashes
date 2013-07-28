# Hashes Makefile

CC=g++
LFLAGS=
CFLAGS=-std=c++11 -Wall -c

all: Hash.o Hashes.o LM.o MD2.o MD4.o MD5.o POLY1305AES.o RIPEMD128.o RIPEMD160.o SHA1.o SHA224.o SHA256.o SHA2_Functions.o SHA384.o SHA512.o

Hashes:
	$(MAKE) -C Hashes

Hash.o: Hash.cpp Hash.h
	$(CC) $(CFLAGS) Hash.cpp

Hashes.o: Hashes.cpp Hashes.h ../common/cryptomath.h ../common/includes.h Hash.h LM.h MD2.h MD4.h MD5.h RIPEMD128.h RIPEMD160.h SHA1.h SHA256.h SHA224.h SHA512.h SHA384.h HMAC.h POLY1305AES.h
	$(CC) $(CFLAGS) Hashes.cpp

LM.o: LM.cpp LM.h ../common/includes.h ../Encryptions/DES.h
	$(CC) $(CFLAGS) LM.cpp

MD2.o: MD2.cpp MD2.h ../common/includes.h Hash.h MD2_Const.h
	$(CC) $(CFLAGS) MD2.cpp

MD4.o: MD4.cpp MD4.h ../common/cryptomath.h ../common/includes.h MD4_Const.h
	$(CC) $(CFLAGS) MD4.cpp

MD5.o: MD5.cpp MD5.h ../common/cryptomath.h ../common/includes.h MD5_Const.h
	$(CC) $(CFLAGS) MD5.cpp

POLY1305AES.o: POLY1305AES.cpp POLY1305AES.h ../common/cryptomath.h ../common/includes.h ../common/integer.h ../Encryptions/AES.h
	$(CC) $(CFLAGS) POLY1305AES.cpp

RIPEMD128.o: RIPEMD128.cpp RIPEMD128.h ../common/cryptomath.h ../common/includes.h Hash.h RIPEMD_Const.h RIPEMD128_Const.h
	$(CC) $(CFLAGS) RIPEMD128.cpp

RIPEMD160.o: RIPEMD160.cpp RIPEMD160.h ../common/cryptomath.h ../common/includes.h Hash.h RIPEMD_Const.h RIPEMD160_Const.h
	$(CC) $(CFLAGS) RIPEMD160.cpp

SHA1.o: SHA1.cpp SHA1.h ../common/cryptomath.h ../common/includes.h Hash.h
	$(CC) $(CFLAGS) SHA1.cpp

SHA224.o: SHA224.cpp SHA224.h SHA256.h
	$(CC) $(CFLAGS) SHA224.cpp

SHA256.o: SHA256.cpp SHA256.h ../common/cryptomath.h ../common/includes.h Hash.h SHA2_Functions.h SHA256_Const.h
	$(CC) $(CFLAGS) SHA256.cpp

SHA2_Functions.o: SHA2_Functions.cpp SHA2_Functions.h
	$(CC) $(CFLAGS) SHA2_Functions.cpp

SHA384.o: SHA384.cpp SHA384.h SHA512.h
	$(CC) $(CFLAGS) SHA384.cpp

SHA512.o: SHA512.cpp SHA512.h ../common/cryptomath.h ../common/includes.h Hash.h SHA2_Functions.h SHA512_Const.h
	$(CC) $(CFLAGS) SHA512.cpp

clean:
	rm -f *.o
