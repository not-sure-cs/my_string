# Makefile for my_string library
# Compiles src/main.c + src/my_string.c -> build/main

# Compiler and flags
CC = clang
CFLAGS = -Wall -Wextra -std=c11 -O2 -g
INCLUDES = -Iinclude

# Directories
TEST_DIR = test
SRC_DIR = src
INCLUDE_DIR = include
BUILD_DIR = build

# Source files
SOURCES = $(wildcard $(SRC_DIR)/*.c)
MAIN_SRC = $(TEST_DIR)/test.c
LIB_SRC = $(SRC_DIR)/my_string.c
OBJECTS = $(BUILD_DIR)/my_string.o

# Target executable
TARGET = $(BUILD_DIR)/test

# Default target
.PHONY: all
all: $(TARGET)

# Link object files into executable
$(TARGET): $(BUILD_DIR) $(OBJECTS) $(MAIN_SRC)
	$(CC) $(CFLAGS) $(INCLUDES) -o $@ $(MAIN_SRC) $(OBJECTS)

# Compile my_string.c into object file
$(BUILD_DIR)/my_string.o: $(LIB_SRC) $(INCLUDE_DIR)/my_string.h | $(BUILD_DIR)
	$(CC) $(CFLAGS) $(INCLUDES) -c $(LIB_SRC) -o $@

# Create build directory if it doesn't exist
$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

# Clean build artifacts
.PHONY: clean
clean:
	rm -rf $(BUILD_DIR)

# Install (copy executable to current directory)
.PHONY: install
install: $(TARGET)
	cp $(TARGET) ./main

# Run the program
.PHONY: run
run: $(TARGET)
	./$(TARGET)

# Format code with clang-format (if available)
.PHONY: format
format:
	clang-format -i $(SRC_DIR)/*.c $(INCLUDE_DIR)/*.h

# Check for memory leaks with valgrind
.PHONY: valgrind
valgrind: $(TARGET)
	valgrind --leak-check=full --show-leak-kinds=all ./$(TARGET)

# Print variables for debugging
.PHONY: info
info:
	@echo "Sources: $(SOURCES)"
	@echo "Objects: $(OBJECTS)"
	@echo "Target: $(TARGET)"
