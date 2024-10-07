all: test.out

linkedlist.o: linkedlist.h linkedlist.c
	gcc -c linkedlist.c -o linkedlist.o

test.out: linkedlist.o test.c
	gcc test.c linkedlist.o -o test.out

clean:
	rm -f *.o *.out