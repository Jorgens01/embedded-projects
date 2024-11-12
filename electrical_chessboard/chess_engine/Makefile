# Compiler to use
CC = gcc -std=c99

# Compiler flags with dependency generation
CFLAGS = -Wall -pedantic-errors -MMD -MP

# Directories
SRC_DIR = src
OBJ_DIR = obj

# Target executable name
TARGET = app

# Source files
SRCS = $(wildcard $(SRC_DIR)/*.c)

# Object files (replace src/ with obj/ and .c with .o)
OBJS = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRCS))

# Dependency files (replace .o with .d)
DEPS = $(OBJS:.o=.d)

# Default target
all: $(TARGET)

# Link object files to create the executable
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

# Rule to compile .c files to .o files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Ensure the obj directory exists
$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

# Clean up build artifacts
clean:
	rm -f $(OBJ_DIR)/*.o $(OBJ_DIR)/*.d $(TARGET)

# Include dependency files
-include $(DEPS)

# Phony targets (not actual files)
.PHONY: all clean