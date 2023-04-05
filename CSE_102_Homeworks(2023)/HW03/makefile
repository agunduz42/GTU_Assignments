CC = gcc
TARGET = test
SRC = main.c
CFLAGS = -Wall -Wextra -Werror

all: compile run

compile: main.c
	$(CC) -o $(TARGET) $(SRC) $(CFLAGS)

run:	
	./$(TARGET)

clean:
	rm -rf $(TARGET)
	rm -rf *.o

.PHONY: all compile run clean