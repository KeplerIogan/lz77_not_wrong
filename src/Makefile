
main: main.o lz77.o
	gcc -Wall main.o lz77.o -o $@

main.o: main.c
	gcc -Wall -c main.c -o $@

lz77.o: lz77.c lz77.h
	gcc -Wall -c lz77.c -o $@
