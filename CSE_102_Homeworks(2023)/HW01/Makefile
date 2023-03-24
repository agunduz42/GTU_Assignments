TARGET = test
CC = gcc
CFLAGS = -Wall -Wextra -Werror
SRC = main.c util.c

all: compile run

compile:
	gcc $(CFLAGS) -o $(TARGET) $(SRC) -lm

run: compile
	./$(TARGET)

clean:
	rm -rf $(TARGET)

.PHONY = all compile run clean