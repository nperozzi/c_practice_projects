# Compiler settings
CC = gcc
CFLAGS = -Wall -g -Isrc -I$(UNITY_DIR)/src

# Directories
SRC_DIR = src
TEST_DIR = tests
UNITY_DIR = ../Unity

# Source and object files
SRC = $(SRC_DIR)/dynamic_string.c
OBJ = $(SRC:.c=.o)

# Test source files and object files
TEST_SRC = $(TEST_DIR)/test_dynamic_string.c
UNITY_SRC = $(UNITY_DIR)/src/unity.c
TEST_OBJ = $(TEST_SRC:.c=.o) $(UNITY_SRC:.c=.o)

# The name of the output executables
TARGET = dynamic_string_manipulator
TEST_TARGET = test_dynamic_string

# Default target: build the main program
all: $(TARGET)

# Build the main program
$(TARGET): $(SRC_DIR)/main.c $(OBJ)
	$(CC) $(CFLAGS) $(SRC_DIR)/main.c $(OBJ) -o $(TARGET)

# Build the unit tests
$(TEST_TARGET): $(OBJ) $(TEST_OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(TEST_OBJ) -o $(TEST_TARGET)

# Rule for compiling .c files into .o files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean up generated files
clean:
	rm -f $(OBJ) $(TEST_OBJ) $(TARGET) $(TEST_TARGET)
