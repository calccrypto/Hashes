# Hashes Library Makefile

all: common Encryptions Hashes

.PHONY: common Encryptions Hashes

common:
	$(MAKE) -C common

Encryptions:
	$(MAKE) -C Encryptions

Hashes:
	$(MAKE) -C Hashes

clean:
	$(MAKE) -C common clean
	$(MAKE) -C Encryptions clean
	$(MAKE) -C Hashes clean
