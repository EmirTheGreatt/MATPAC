# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -O2

# Library name
LIB = MATPAC.a

# Source files (all .c except tester.c)
SRC = $(filter-out tester.c,$(wildcard *.c))

# Object files
OBJ = $(SRC:.c=.o)

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
	rm -f $(OBJ) $(LIB)

.PHONY: all clean