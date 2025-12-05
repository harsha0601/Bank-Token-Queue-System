# Makefile for Bank Token Queue System
CC = gcc
CFLAGS = -Wall -Wextra -std=c99
LIBS = -lncurses

TARGET = bank_queue
SOURCES = main.c

# Default target
all: $(TARGET)

# Build the executable
$(TARGET): $(SOURCES)
	$(CC) $(CFLAGS) -o $(TARGET) $(SOURCES) $(LIBS)

# Clean build artifacts
clean:
	rm -f $(TARGET)

# Run the program
run: $(TARGET)
	./$(TARGET)

# Compile and run
compile_run: clean $(TARGET) run

# Phony targets (not actual files)
.PHONY: all clean run compile_run
