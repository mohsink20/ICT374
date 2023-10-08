TARGET = ex4

CC = gcc
CFLAGS = -Wall -Wextra -Werror

SOURCES = main.c getArray.c
OBJS = main.o getArray.o

all: $(TARGET)

$(TARGET): $(OBJS)
		$(CC) $(OBJS) -o $(TARGET)

main.o: main.c ex4.h
	$(CC) $(CFLAGS) -c main.c

getArray.o: getArray.c ex4.h
		$(CC) $(CFLAGS) -c getArray.c

clean:
	rm -f $(TARGET) $(OBJS)
