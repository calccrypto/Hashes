# Hashes Library Test Makefile
CXX?=g++
CXXFLAGS=-std=c++11 -Wall -g -I../../googletest/googletest/include -I..
LDFLAGS=-lHashes -lgmp -lgmpxx -L.. -L../../googletest/googlemock/gtest -lgtest -lpthread
TARGET=tests

include testcases/objects.mk

debug: CXXFLAGS += -g
debug: all

all: $(TARGET)

.PHONY: lib testcases run clean clean-all

lib:
	$(MAKE) -C ..

testcases:
	$(MAKE) -C testcases

$(TARGET): tests.cpp lib testcases
	$(CXX) $(CXXFLAGS) tests.cpp $(addprefix testcases/, $(HASHES_TESTCASES_OBJECTS)) $(LDFLAGS) -o $(TARGET)

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(TARGET)

clean-all:  clean
	$(MAKE) clean -C testcases
	$(MAKE) clean-all -C ..