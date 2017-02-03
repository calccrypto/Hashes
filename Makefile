# Hashes Library Makefile
AR=ar
TARGET=libHashes.a

all: $(TARGET)

.PHONY: common Encryptions Hashes clean clean-all

common:
	$(MAKE) -C common

Encryptions:
	$(MAKE) -C Encryptions

Hashes:
	$(MAKE) -C Hashes

$(TARGET): common Encryptions Hashes
	$(AR) -r $(TARGET) ./common/*.o ./Encryptions/*.o ./Hashes/*.o

clean:
	rm -f *.a

clean-all:  clean
	$(MAKE) clean -C common
	$(MAKE) clean -C Encryptions
	$(MAKE) clean -C Hashes
