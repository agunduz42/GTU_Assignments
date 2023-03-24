CC = gcc
TARGET = test
SRC = main.c

all: clean compile run

compile: main.c
	@echo "-------------------------------------------"
	@echo "Compiling..."
	@$(CC) -o $(TARGET) $(SRC)

run:
	@echo "-------------------------------------------"
	@echo "Running the tests..."
	@echo "========================================================================="
	@./$(TARGET)
	@echo "========================================================================="
	@echo "Completed tests..."

clean:
	@echo "-------------------------------------------"
	@echo "Removing compiled files"
	@rm -rf $(TARGET)