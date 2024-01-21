all: quadraticroots

quadraticroots: main.o quadraticroots.o
	gcc -o quadraticroots main.o quadraticroots.o -lm

main.o: main.c quadraticroots.h
	gcc -c main.c

quadraticroots.o: quadraticroots.c quadraticroots.h
	gcc -c quadraticroots.c

clean:
	rm -f *.o
