CC = gcc
TARGET = test
SRC = main.c util.c

all: clean compile run

compile: main.c util.c util.h
	@echo "-------------------------------------------"
	@echo "Compiling..."
	@gcc -o $(TARGET) $(SRC)

run:
	@echo "-------------------------------------------"
	@echo "Running the tests..."
	@echo "==========================================================================="
	@./$(TARGET)
	@echo "==========================================================================="
	@echo "Completed tests..."

clean:
	@echo "-------------------------------------------"
	@echo "Removing compiled files"
	@rm -rf $(TARGET)