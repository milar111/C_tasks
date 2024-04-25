all: tests.out

dynamicArrays.o: dynamicArrays.c dynamicArrays.h
	gcc -c dynamicArrays.c -o dynamicArrays.out

tests.exe: dynamicArrays.o tests.c
	gcc tests.c dynamicArrays.o -o tests.exe

clean:
	rm -f *.o*.exe