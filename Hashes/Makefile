# Hashes Makefile
CXX?=g++
CXXFLAGS=-std=c++11 -Wall -c

debug: CXXFLAGS += -g
debug: all

all: Hash.o Hashes.o Keccak.o LM.o MD2.o MD4.o MD5.o POLY1305AES.o RIPEMD128.o RIPEMD160.o SHA1.o SHA224.o SHA256.o SHA2_Functions.o SHA384.o SHA512.o SHA3.o

.PHONY: clean

Hash.o: Hash.cpp Hash.h
	$(CXX) $(CXXFLAGS) Hash.cpp

Hashes.o: Hashes.cpp Hashes.h
	$(CXX) $(CXXFLAGS) Hashes.cpp

Keccak.o: Keccak.cpp Keccak.h ../common/cryptomath.h ../common/includes.h Keccak_Const.h
	$(CXX) $(CXXFLAGS) Keccak.cpp

LM.o: LM.cpp LM.h ../common/includes.h ../Encryptions/DES.h
	$(CXX) $(CXXFLAGS) LM.cpp

MD2.o: MD2.cpp MD2.h ../common/includes.h Hash.h MD2_Const.h
	$(CXX) $(CXXFLAGS) MD2.cpp

MD4.o: MD4.cpp MD4.h ../common/cryptomath.h ../common/includes.h MD4_Const.h
	$(CXX) $(CXXFLAGS) MD4.cpp

MD5.o: MD5.cpp MD5.h ../common/cryptomath.h ../common/includes.h MD5_Const.h
	$(CXX) $(CXXFLAGS) MD5.cpp

POLY1305AES.o: POLY1305AES.cpp POLY1305AES.h ../common/cryptomath.h ../common/includes.h ../Encryptions/AES.h
	$(CXX) $(CXXFLAGS) POLY1305AES.cpp

RIPEMD128.o: RIPEMD128.cpp RIPEMD128.h ../common/cryptomath.h ../common/includes.h Hash.h RIPEMD_Const.h RIPEMD128_Const.h
	$(CXX) $(CXXFLAGS) RIPEMD128.cpp

RIPEMD160.o: RIPEMD160.cpp RIPEMD160.h ../common/cryptomath.h ../common/includes.h Hash.h RIPEMD_Const.h RIPEMD160_Const.h
	$(CXX) $(CXXFLAGS) RIPEMD160.cpp

SHA1.o: SHA1.cpp SHA1.h ../common/cryptomath.h ../common/includes.h Hash.h
	$(CXX) $(CXXFLAGS) SHA1.cpp

SHA224.o: SHA224.cpp SHA224.h SHA256.h
	$(CXX) $(CXXFLAGS) SHA224.cpp

SHA256.o: SHA256.cpp SHA256.h ../common/cryptomath.h ../common/includes.h Hash.h SHA2_Functions.h SHA256_Const.h
	$(CXX) $(CXXFLAGS) SHA256.cpp

SHA2_Functions.o: SHA2_Functions.cpp SHA2_Functions.h
	$(CXX) $(CXXFLAGS) SHA2_Functions.cpp

SHA384.o: SHA384.cpp SHA384.h SHA512.h
	$(CXX) $(CXXFLAGS) SHA384.cpp

SHA512.o: SHA512.cpp SHA512.h ../common/cryptomath.h ../common/includes.h Hash.h SHA2_Functions.h SHA512_Const.h
	$(CXX) $(CXXFLAGS) SHA512.cpp

SHA3.o: SHA3.cpp SHA3.h ../common/cryptomath.h ../common/includes.h Keccak_Const.h
	$(CXX) $(CXXFLAGS) SHA3.cpp

clean:
	rm -f *.o
