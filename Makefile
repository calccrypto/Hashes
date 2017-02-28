# Hashes Library Makefile
AR=ar
TARGET=libHashes.a

include common/sources.make
COMMON_OBJECTS=$(addprefix common/, $(COMMON_SOURCES:.cpp=.o))

include Encryptions/sources.make
ENCRYPTIONS_OBJECTS=$(addprefix Encryptions/, $(ENCRYPTIONS_SOURCES:.cpp=.o))

include Hashes/sources.make
HASHES_OBJECTS=$(addprefix Hashes/, $(HASHES_SOURCES:.cpp=.o))

all: $(TARGET)

.PHONY: common Encryptions Hashes clean clean-all

common:
	$(MAKE) -C common

Encryptions:
	$(MAKE) -C Encryptions

Hashes:
	$(MAKE) -C Hashes

$(TARGET): common Encryptions Hashes
	$(AR) -r $(TARGET) $(COMMON_OBJECTS) $(ENCRYPTIONS_OBJECTS) $(HASHES_OBJECTS)

clean:
	rm -f $(TARGET)

clean-all:  clean
	$(MAKE) clean -C common
	$(MAKE) clean -C Encryptions
	$(MAKE) clean -C Hashes
