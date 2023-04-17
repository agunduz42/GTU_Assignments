CC = gcc
SRC = main.c
TARGET = test
CFLAGS = -Wall -Wextra -Werror

all: compile run

compile: $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o $(TARGET)

run: test
	./$(TARGET)

clean: $(TARGET)
	rm -rf $(TARGET) *.o

phony: all compile run clean