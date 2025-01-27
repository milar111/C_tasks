all: program.out
	./program.out

program.out: main.o figure.o node.o tree.o
	gcc main.o figure.o node.o tree.o -o program.out

main.o: main.c figure.h node.h tree.h
	gcc -c main.c -o main.o

figure.o: figure.c figure.h
	gcc -c figure.c -o figure.o

node.o: node.c node.h figure.h
	gcc -c node.c -o node.o

tree.o: tree.c tree.h node.h figure.h
	gcc -c tree.c -o tree.o

clean:
	del *.out *.o

#rm -f *.out *.o

