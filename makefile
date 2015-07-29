all : etest p4 binread binwrite

binread: binread.o
	gcc -g -lncurses -lreadline binread.o -o binread

binwrite: binwrite.o func.o
	gcc -g -lncurses -lreadline binwrite.o func.o  -o binwrite
p4: p4.o func.o 
	gcc -g -lncurses -lreadline func.o  p4.o -o p4

etest: etest.o func.o
	gcc -g -lncurses -lreadline func.o etest.o -o etest

etest.o: etest.c etest.h
	gcc -g -c etest.c

p4.o: p4.c p4.h etest.h
	gcc -g -c p4.c

func.o : func.c etest.h
	gcc -g -c func.c

binread.o: binread.c etest.h
	gcc -g -c binread.c

binwrite.o: binwrite.c 
	gcc -g -c binwrite.c

clean:
	rm -f *.o etest p4 func binwrite binread

docs:
	doxygen
	chmod a+r html/*
	cp -p -r html/* ~/public_html/cs2301/assig5

