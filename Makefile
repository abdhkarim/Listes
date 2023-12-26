CC = gcc
CCFLAGS = -Wall -g

all: main


listes.o:	listes.c listes.h
	${CC} ${CCFLAGS} -c listes.c

main.o:	main.c
	${CC} ${CCFLAGS} -c main.c

main:	main.o listes.o
	${CC} ${CCFLAGS} -o main main.o listes.o

clean:
	rm *.o ; rm main
