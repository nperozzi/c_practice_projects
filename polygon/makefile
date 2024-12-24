# Compiler settings
CC = gcc
CFLAGS = -Wall -g -Isrc -I$(UNITY_DIR)/src

# Directories
SRC_DIR = src
TEST_DIR = tests
UNITY_DIR = ../Unity

# Src and obj files:
# SRC = $(SRC_DIR)/
OBJ = $(SRC:.c = .o)

# Test src files and obj files
TEST_SRC =
TEST_OBJ =
UNITY_SRC = 

# Name of the output executables:
TARGET = polygon
TEST_TARGET = test_polygon

# Default target: builds the main program
all: $(TARGET)

# Build the main program
$(TARGET): $(SRC_DIR)/main.c $(OBJ)
	$(CC) $(CFLAGS) $(SRC_DIR)/main.c $(OBJ) -o $(TARGET)
	
# Build the unit tests program
$(TEST_TARGET): $(OBJ) $(TEST_OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(TEST_OBJ) -o $(TEST_TARGET)

# Rules for compiling .c files into .o files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean up generated files
clean:
	rm -f $(OBJ) $(TEST_OBJ) $(TARGET) $(TEST_TARGET)

