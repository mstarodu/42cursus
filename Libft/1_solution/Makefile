# Compiler and flags
CC=gcc
CFLAGS=-Wall -Wextra -Werror

# Name of your executable
NAME=libft.a

# Source and object files
SRC= $(filter-out tester.c, $(wildcard *.c))

OBJ=$(SRC:.c=.o)

# Default target
all: $(NAME)

# Rule for building the final executable
$(NAME): $(OBJ)
	ar rcs $@ $^

# Generic rule for building object files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean up object files
clean:
	rm -f $(OBJ)

# Full clean (objects and executable)
fclean: clean
	rm -f $(NAME)

# Rebuild everything
re: fclean all

# Rule to prevent make from getting confused.
.PHONY: all clean fclean re
