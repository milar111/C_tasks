all: lz77.exe
	.\lz77.exe

main.o: main.c lz77.h
	gcc -c main.c -o main.o

lz77.o: lz77.c lz77.h
	gcc -c lz77.c -o lz77.o

lz77.exe: main.o lz77.o
	gcc main.o lz77.o -o lz77.exe

test_compress: lz77.exe
	.\lz77.exe compress test.txt compressed.txt 20 10

test_decompress: lz77.exe
	.\lz77.exe decompress compressed.txt decompressed.txt


test: test_compress test_decompress

clean:
	del /Q *.o *.exe compressed.txt decompressed.txt 2>nul
