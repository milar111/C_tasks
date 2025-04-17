all: main.out
	./main.out

main.out: main.o graph.o pathfinder.o
	gcc main.o graph.o pathfinder.o -o main.out -lm

main.o: main.c graph.h pathfinder.h
	gcc -c main.c -o main.o

graph.o: graph.c graph.h
	gcc -c graph.c -o graph.o

pathfinder.o: pathfinder.c pathfinder.h graph.h
	gcc -c pathfinder.c -o pathfinder.o

clean:
	del *.out *.o

#rm -f *.out *.o
