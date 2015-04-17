# Hashes Makefile
CXX?=g++
LFLAGS=-lgmpxx -lgmp
CFLAGS=-std=c++11 -Wall -c

debug: CFLAGS += -g
debug: all

all: Hash.o Hashes.o Keccak.o LM.o MD2.o MD4.o MD5.o POLY1305AES.o RIPEMD128.o RIPEMD160.o SHA1.o SHA224.o SHA256.o SHA2_Functions.o SHA384.o SHA512.o SHA3.o

Hash.o: Hash.cpp Hash.h
	$(CXX) $(CFLAGS) Hash.cpp

Hashes.o: Hashes.cpp Hashes.h
	$(CXX) $(CFLAGS) Hashes.cpp

Keccak.o: Keccak.cpp Keccak.h ../common/cryptomath.h ../common/includes.h Keccak_Const.h
	$(CXX) $(CFLAGS) Keccak.cpp

LM.o: LM.cpp LM.h ../common/includes.h ../Encryptions/DES.h
	$(CXX) $(CFLAGS) LM.cpp

MD2.o: MD2.cpp MD2.h ../common/includes.h Hash.h MD2_Const.h
	$(CXX) $(CFLAGS) MD2.cpp

MD4.o: MD4.cpp MD4.h ../common/cryptomath.h ../common/includes.h MD4_Const.h
	$(CXX) $(CFLAGS) MD4.cpp

MD5.o: MD5.cpp MD5.h ../common/cryptomath.h ../common/includes.h MD5_Const.h
	$(CXX) $(CFLAGS) MD5.cpp

POLY1305AES.o: POLY1305AES.cpp POLY1305AES.h ../common/cryptomath.h ../common/includes.h ../Encryptions/AES.h
	$(CXX) $(CFLAGS) $(LFLAGS) POLY1305AES.cpp

RIPEMD128.o: RIPEMD128.cpp RIPEMD128.h ../common/cryptomath.h ../common/includes.h Hash.h RIPEMD_Const.h RIPEMD128_Const.h
	$(CXX) $(CFLAGS) RIPEMD128.cpp

RIPEMD160.o: RIPEMD160.cpp RIPEMD160.h ../common/cryptomath.h ../common/includes.h Hash.h RIPEMD_Const.h RIPEMD160_Const.h
	$(CXX) $(CFLAGS) RIPEMD160.cpp

SHA1.o: SHA1.cpp SHA1.h ../common/cryptomath.h ../common/includes.h Hash.h
	$(CXX) $(CFLAGS) SHA1.cpp

SHA224.o: SHA224.cpp SHA224.h SHA256.h
	$(CXX) $(CFLAGS) SHA224.cpp

SHA256.o: SHA256.cpp SHA256.h ../common/cryptomath.h ../common/includes.h Hash.h SHA2_Functions.h SHA256_Const.h
	$(CXX) $(CFLAGS) SHA256.cpp

SHA2_Functions.o: SHA2_Functions.cpp SHA2_Functions.h
	$(CXX) $(CFLAGS) SHA2_Functions.cpp

SHA384.o: SHA384.cpp SHA384.h SHA512.h
	$(CXX) $(CFLAGS) SHA384.cpp

SHA512.o: SHA512.cpp SHA512.h ../common/cryptomath.h ../common/includes.h Hash.h SHA2_Functions.h SHA512_Const.h
	$(CXX) $(CFLAGS) SHA512.cpp

SHA3.o: SHA3.cpp SHA3.h ../common/cryptomath.h ../common/includes.h Keccak_Const.h
	$(CXX) $(CFLAGS) SHA3.cpp

clean:
	rm -f *.o
