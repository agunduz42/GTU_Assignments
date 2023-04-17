TARGET = test
SRC = main.c
CFLAGS = -Wall -Wextra -Werror
CC = gcc

all: compile run

compile: $(SRC)
	$(CC) -o $(TARGET) $(CFLAGS) $(SRC)

run: $(TARGET)
	./$(TARGET)

clean:
	rm -rf $(TARGET)
	rm -rf *.o