TARGET = test
SRC = main.c util.c util.h
CC = gcc

all: compile run

compile: $(SRC)
	@$(CC) -o $(TARGET) $(SRC)
	@echo "_____Compile Success_____"

run: $(TARGET)
	@echo "_____$(TARGET) Executed_____"
	@./$(TARGET)
	@echo "\n_____$(TARGET) Completed_____"

clean:
	@rm -rf *.out
	@rm -rf $(TARGET)