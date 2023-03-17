CC = gcc
TARGET = test
CFLAGS = -Wall -Wextra -Werror
SRC = main.c

all: compile run

compile: 
	$(CC) -o $(TARGET) $(CFLAGS) $(SRC) -lm

run:
	./$(TARGET)

clean:
	rm -rf $(TARGET)

.PHONY: all compile run clean