TARGET = test
SRC = main.c
CC = gcc

all: compile run

compile: main.c
	$(CC) -o $(TARGET) $(SRC)

run:$(TARGET)
	./$(TARGET)

clean:
	rm -rf $(TARGET)
	rm -rf *.out