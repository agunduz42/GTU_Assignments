SRC = main.c
TARGET = test

all: compile run

compile:
	gcc -o $(TARGET) $(SRC) -lm
	@echo "___compile success___\n"

run:
	./$(TARGET)
	@echo "\n\n___run_success___\n"

clean:
	rm -rf $(TARGET)