# Hashes Library Makefile
AR=ar
TARGET=libHashes.a

all: $(TARGET)

.PHONY: common Encryptions Hashes

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
	$(MAKE) -C common clean
	$(MAKE) -C Encryptions clean
	$(MAKE) -C Hashes clean
