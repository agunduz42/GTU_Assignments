CC = gcc
SRC = main.c
TARGET = test

all: compile run

compile: $(SRC)
	$(CC) $(SRC) -o $(TARGET)

run: test
	./$(TARGET)

clean: $(TARGET)
	rm -rf $(TARGET) *.o

phony: all compile run clean