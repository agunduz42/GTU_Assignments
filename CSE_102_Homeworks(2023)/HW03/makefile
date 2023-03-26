CC = gcc
TARGET = test
SRC = main.c

all: compile run

compile: main.c
	@$(CC) -o $(TARGET) $(SRC)

run:	
	./$(TARGET)

clean:
	rm -rf $(TARGET)