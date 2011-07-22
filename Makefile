# Temporary Makefile

all: source

source: force_look
	make -C source

tests: force_look source
	make -C source tests

lessons: force_look source
	make -C lessons

.PHONY: clean
clean:
	make -C source clean
	make -C lessons clean

.PHONY: force_look
	true
