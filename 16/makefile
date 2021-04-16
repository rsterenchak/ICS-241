program: bitwise16.o printbits.o
	gcc bitwise16.o printbits.c -o program

bitwise16.o: bitwise16.c printbits.h
	gcc -c bitwise16.c

printbits.o: printbits.c printbits.h
	gcc -c printbits.c