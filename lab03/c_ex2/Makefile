TARGET = ex2

CC = gcc
CFLAGS = -Wall -Wextra -Werror

SOURCES = main.c fillArray.c
OBJS = main.o fillArray.o

all: $(TARGET)

$(TARGET): $(OBJS)
		$(CC) $(OBJS) -o $(TARGET)

main.o: main.c ex2.h
	$(CC) $(CFLAGS) -c main.c

fillArray.o: fillArray.c ex2.h
		$(CC) $(CFLAGS) -c fillArray.c

clean:
	rm -f $(TARGET) $(OBJS)
