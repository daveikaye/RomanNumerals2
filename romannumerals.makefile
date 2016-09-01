CFLAGS=-Wall
LIBS=-lcheck
COMPILER=gcc-4.8

all: romannumerals

romannumerals: roman_numerals.o
	$(COMPILER) -o romannumerals roman_numerals.o

roman_numerals.o: src/roman_numerals.c src/roman_numerals.h
	$(COMPILER) $(CFLAGS) -c src/roman_numerals.c

test: romannumerals-test
	./romannumerals-test

romannumerals-test: implementation-test.o roman_numerals.o
	$(COMPILER) -o romannumerals-test roman_numerals.o implementation-test.o $(LIBS)

implementation-test.o: implementation-test.c src/roman_numerals.h
	$(COMPILER) $(CFLAGS) -c implementation-test.c

implementation-test.c: test/roman_numerals-test.check
	checkmk test/roman_numerals-test.check >implementation-test.c
