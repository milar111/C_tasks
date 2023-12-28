all: safeadd.out safesubtract.out safemultiply.out safedivide.out

safeadd.out: safeint.o safeadd.c safeint.h
	gcc safeadd.c safeint.o -o safeadd.out

safesubtract.out: safeint.o safesubtract.c safeint.h
	gcc safesubtract.c safeint.o -o safesubtract.out

safemultiply.out: safeint.o safemultiply.c safeint.h
	gcc safemultiply.c safeint.o -o safemultiply.out

safedivide.out: safeint.o safedivide.c safeint.h
	gcc safedivide.c safeint.o -o safedivide.out

safeint.o: safeint.c safeint.h
	gcc -c safeint.c -o safeint.o

clean:
	rm -f *.out *.o
