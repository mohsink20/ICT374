CC = gcc
CFLAGS = -Wall

prog: main.o token.o
	$(CC) main.o token.o -o prog

main.o: main.c token.h
	$(CC) $(CFLAGS) -c main.c

token.o: token.c token.h
		$(CC) $(CFLAGS) -c token.c

clean:
	rm -f prog main.o token.o
