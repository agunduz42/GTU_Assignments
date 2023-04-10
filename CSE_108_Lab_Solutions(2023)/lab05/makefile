CC = gcc
TARGET = test
SRC = part1.c

all: compile run

compile:
	$(CC) -o $(TARGET) $(SRC) -lm

run:
	./$(TARGET)

clean:
	rm -rf $(TARGET)
	rm -rf *.o