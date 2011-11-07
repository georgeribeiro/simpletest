OPTIONS = -fnested-functions

all: main.c simpletest.o
	gcc $(OPTIONS) -o main main.c simpletest.o

simpletest.o: simpletest.c simpletest.h
	gcc -c simpletest.c

clean:
	@rm -rf *~ \#* *.o main
