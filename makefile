CC=gcc
CFLAGS=-I

bisectmake: bisect.c
	$(CC) -o bisect.o bisect.c -lm
