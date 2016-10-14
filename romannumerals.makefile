CFLAGS=-Wall `pkg-config --cflags check`
LIBS=`pkg-config --libs check`
COMPILER=gcc

all: romannumerals

romannumerals: roman_numerals.o
	$(COMPILER) -o romannumerals roman_numerals.o

roman_numerals.o:
	$(COMPILER) $(CFLAGS) -c src/*.c

test: romannumerals-test
	./romannumerals-test

romannumerals-test: implementation-test.o roman_numerals.o
	$(COMPILER) -o romannumerals-test *.o $(LIBS)

implementation-test.o: implementation-test.c
	$(COMPILER) $(CFLAGS) -c implementation-test.c

implementation-test.c:
	checkmk test/first.check test/*test.check test/last.check >implementation-test.c

clean:
	$(RM) *.o *.c romannumerals-test
