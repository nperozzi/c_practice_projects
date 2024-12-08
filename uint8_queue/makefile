# Compiler settings
CC = gcc
CFLAGS = -Wall -g -Isrc -I$(UNITY_DIR)/src -mconsole -mno-win32

# Directories
SRC_DIR = src
TEST_DIR = tests
UNITY_DIR = ../Unity

# Source and object files for the main program
SRC = $(SRC_DIR)/uint8-queue.c
OBJ = $(SRC:.c=.o)

# Test source and object files
TEST_SRC = $(TEST_DIR)/test_uint8_queue_demo.c
TEST_OBJ = $(TEST_SRC:.c=.o)
UNITY_SRC = $(UNITY_DIR)/src/unity.c
UNITY_OBJ = $(UNITY_SRC:.c=.o)

# The name of the output executables
TARGET = uint8_queue_demo
TEST_TARGET = test_uint8_queue_demo

# Default target: build the main program
all: $(TARGET)

# Build the main program
$(TARGET): $(OBJ) $(SRC_DIR)/main.c
	$(CC) $(CFLAGS) $(OBJ) $(SRC_DIR)/main.c -o $(TARGET)

# Build the unit tests
$(TEST_TARGET): $(OBJ) $(TEST_OBJ) $(UNITY_OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(TEST_OBJ) $(UNITY_OBJ) -o $(TEST_TARGET)

# Rule for compiling .c files into .o files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Run the tests
test: $(TEST_TARGET)
	./$(TEST_TARGET)

# Clean up generated files
clean:
	rm -f $(OBJ) $(TEST_OBJ) $(UNITY_OBJ) $(TARGET) $(TEST_TARGET)
