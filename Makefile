# Hashes Library Makefile

all: common Encryptions Hashes

.PHONY: common Encryptions

common:
	$(MAKE) -C common

Encryptions:
	$(MAKE) -C Encryptions

Hashes:
	$(MAKE) -C Hashes

clean:
	rm -f common/*.o Encryptions/*.o Hashes/*.o