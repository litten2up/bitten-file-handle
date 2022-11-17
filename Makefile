.DEFAULT_GOAL := build
mainc: src/main.c src/bit_file.c
	gcc -c src/main.c -o build/main.o
bitfilec: src/bit_file.c src/bit_file.h
	gcc -c src/bit_file.c -o build/bitfile.o
build: mainc bitfilec
	gcc build/main.o build/bitfile.o -o bin/bitfile

	