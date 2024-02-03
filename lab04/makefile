#makefile
lab04: lab04.o ghcontrol.o led2472g.o
	gcc -g -o lab04 lab04.o ghcontrol.o led2472g.o
lab04.o: lab04.c ghcontrol.h
	gcc -g -c lab04.c
ghcontrol.o: ghcontrol.c ghcontrol.h
	gcc -g -c ghcontrol.c
led2472g.o: led2472g.c led2472g.h
	gcc -g -c led2472g.c
.PHONY: clean
clean:
	rm -f *.o
	touch *	
