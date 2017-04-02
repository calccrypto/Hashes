# Hashes Library Makefile
AR=ar
TARGET=libHashes.a

include common/objects.mk
include Encryptions/objects.mk
include Hashes/objects.mk

.PHONY: common Encryptions Hashes clean clean-all

all: $(TARGET)

common:
	$(MAKE) -C common

Encryptions:
	$(MAKE) -C Encryptions

Hashes:
	$(MAKE) -C Hashes

$(TARGET): common Encryptions Hashes
	$(AR) -r $(TARGET) $(addprefix common/, $(COMMON_OBJECTS)) $(addprefix Encryptions/, $(ENCRYPTIONS_OBJECTS)) $(addprefix Hashes/, $(HASHES_OBJECTS))

clean:
	rm -f $(TARGET)

clean-all:  clean
	$(MAKE) clean -C common
	$(MAKE) clean -C Encryptions
	$(MAKE) clean -C Hashes
