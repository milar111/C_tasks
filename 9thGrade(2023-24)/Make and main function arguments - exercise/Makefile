all: help.out strlength.out strconcat.out strcompare.out

help.out: main.c
    gcc -o help.out main.c

mystrings.o: mystrings.c
    gcc -c mystrings.c -o mystrings.o 

strlength.out: strlength.c mystrings.o
    gcc strlength.c mystrings.o -o strlength.out 

strconcat.out: strconcat.c mystrings.o
    gcc strconcat.c mystrings.o -o strconcat.out 

strcompare.out: strcompare.c mystrings.o
    gcc strcompare.c mystrings.o -o strcompare.out 

clean:
    rm -f *.out *.o
