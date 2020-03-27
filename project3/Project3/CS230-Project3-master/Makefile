CC = gcc
CFLAGS	= -g -Wall

default: wordfreak

wordfreak: main.o BST.o parser.o
	$(CC) $(CFLAGS) -o wordfreak main.o BST.o parser.o

main.o:	main.c BST.h parser.h
	$(CC) $(CFLAGS) -c main.c

BST.o:	BST.c BST.h
	$(CC) $(CFLAGS) -c BST.c

parser.o: parser.c parser.h
	$(CC) $(CFLAGS) -c parser.c
clean: 
	$(RM) count *.o *~
