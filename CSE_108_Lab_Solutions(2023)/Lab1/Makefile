CC = gcc
TARGET = test
CFLAGS = -Wall -Wextra -Werror
SRC = main.c

all: clean compile run

compile:
	@gcc $(CFLAGS) -o $(TARGET) $(SRC)

run:
	@./$(TARGET)

clean:
	@rm -rf $(TARGET)

.PHONY: all compile run clean
