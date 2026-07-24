# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -O2 -IInclude

# Library name
LIB = MATPAC.a

# Folders
SRC_DIR = Src
TEST_DIR = Tests

# Source files (all .c inside Src/)
SRC = $(wildcard $(SRC_DIR)/*.c)

# Object files (placed alongside source files)
OBJ = $(SRC:.c=.o)

# Tester
TEST = $(TEST_DIR)/tester.c
PROGRAM = program

# Default target
all: $(LIB)

# Build the static library
$(LIB): $(OBJ)
	ar rcs $@ $^

# Compile .c to .o
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean up
clean:
	rm -f $(SRC_DIR)/*.o $(LIB) $(PROGRAM)

test: $(LIB)
	$(CC) $(CFLAGS) $(TEST) $(LIB) -o $(PROGRAM)

.PHONY: all clean test