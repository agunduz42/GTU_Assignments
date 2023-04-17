TARGET = test
SRC = main.c
CC = gcc
CFLAGS = -Wall -Wextra -Werror

all: compile run

compile: $(SRC)
	$(CC) -o $(TARGET) $(CFLAGS) $(SRC)

run: $(TARGET)
	./$(TARGET)

clean:
	rm -rf *.out
	rm -rf $(TARGET)