all: program.out
	./program.out

program.out: main.o functions.o header.h
	gcc main.o functions.o -o program.out

main.o: main.c header.h
	gcc -c main.c -o main.o

functions.o: functions.c header.h
	gcc -c functions.c -o functions.o

clean:
	del *.out *.o

#rm -f *.out *.o
