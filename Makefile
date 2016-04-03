CC=gcc
CFLAGS=-Wall --std=c11

treeheap.o: treeheap.c
	$(CC) $(CFLAGS) -o treeheap.o -c treeheap.c

test: test.c treeheap.o
	$(CC) $(CFLAGS) -o test test.c treeheap.o

all: test

clean:
	rm -f test treeheap.o

