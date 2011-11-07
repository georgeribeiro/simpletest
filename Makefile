CFLAGS = -fnested-functions
CC = gcc

all: main.c simpletest.o
	$(CC) -o main main.c simpletest.o

simpletest.o: simpletest.c simpletest.h
	$(CC) -c simpletest.c

clean:
	@rm -rf *~ \#* *.o main

test: all
	./main