SRC = main.c util.c util.h
TARGET = test
CC = gcc

all: compile run

compile:$(SRC)
	@$(CC) -o $(TARGET) $^ -lm
	@echo "\n_____compile_success_____\n"

run:$(TARGET)
	@echo "_____test_executed_____\n"
	@./$(TARGET)
	@echo "\n\n_____run_success_____\n"

clean:
	@rm -rf $(TARGET)
	@echo "\n_____cleaned_____\n"