all: main.out

quadraticroots.o: quadraticroots.h quadraticroots.c main.c
	gcc -c quadraticroots.c -o quadraticroots.o 

main.out: main.c quadraticroots.h quadraticroots.o
	gcc main.c quadraticroots.o -o main.out

clean:
	rm -f *.o *.out
