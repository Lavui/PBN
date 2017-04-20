CFLAGS=-std=c99
CC=gcc
LDLIBS=-lcunit

.PHONY: all do_test do_test_codif do_test_itu do_test_streamencoder clean

all: morse test_codif test_itu test_streamencoder test

do_test_codif: test_codif clean
	./test_codif
do_test_itu: test_itu clean
	./test_itu
do_test_streamencoder: test_streamencoder clean
	./test_streamencoder
do_test: test clean
	./test

clean:
	\rm -f *~ *.o

veryclean: clean
	\rm -f morse test_codif test_itu test_streamencoder test

test_codif: codif.o
test_itu: codif.o itu.o
test_streamencoder: codif.o itu.o streamencoder.o
test: codif.o itu.o streamencoder.o
morse: codif.o itu.o streamencoder.o

codif.o: codif.h
itu.o: itu.h codif.h
streamencoder.o: streamencoder.h itu.h codif.h

