CFLAGS=-Wall
LIBS=-lcheck

all: romannumerals

romannumerals: roman_numerals.o
	gcc -o romannumerals roman_numerals.o

roman_numerals.o: src/roman_numerals.c src/roman_numerals.h
	gcc $(CFLAGS) -c src/roman_numerals.c

test: romannumerals-test
	./romannumerals-test

romannumerals-test: check_roman_numerals.o roman_numerals.o
	gcc -o romannumerals-test roman_numerals.o check_roman_numerals.o $(LIBS)

check_roman_numerals.o: test/check_roman_numerals.c src/roman_numerals.h
	gcc $(CFLAGS) -c test/check_roman_numerals.c