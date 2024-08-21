# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -Iinclude -g

# Source directories
SRC_DIR = src
TOOLS_DIR = $(SRC_DIR)/tools
OBJ_DIR = obj

# Target executable
TARGET = bin/game

# Find all .c files in src/ and tools/ directories
SRCS = $(wildcard $(SRC_DIR)/*.c) $(wildcard $(TOOLS_DIR)/*.c)

# Generate object files in the obj directory
OBJS = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRCS))

# Default target
all: $(TARGET)

# Build the target executable
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

# Compile .c files to .o files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Create obj directory if it doesn't exist
$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

# Clean up generated files
clean:
	rm -rf $(OBJ_DIR) $(TARGET)

run:
	./$(TARGET)

# Phony targets
.PHONY: all clean

