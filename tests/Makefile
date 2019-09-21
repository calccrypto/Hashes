# Hashes Library Test Makefile
CXX?=g++
CXXFLAGS=-std=c++11 -Wall -g -D_POSIX_C_SOURCE=200809L -I../../googletest/googletest/include -I..
LDFLAGS=-lHashes -lgmp -lgmpxx -L.. -L../../googletest/build/lib -lgtest -lgtest_main -lpthread
TARGET=tests

include objects.mk

debug: CXXFLAGS += -g
debug: all

.PHONY: clean clean-all

all: $(TARGET)

../libHashes.a:
	$(MAKE) -C ..

$(HASHES_TESTCASES_OBJECTS): %.o : %.cpp testvectors/datadigest.h testvectors/keydatadigest.h
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(TARGET): ../libHashes.a $(HASHES_TESTCASES_OBJECTS)
	$(CXX) $(CXXFLAGS) $(HASHES_TESTCASES_OBJECTS) $(LDFLAGS) -o $(TARGET)

test: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(HASHES_TESTCASES_OBJECTS) $(TARGET)

clean-all:  clean
	$(MAKE) clean-all -C ..
