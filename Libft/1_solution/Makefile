# Compiler and flags
CC=gcc
CFLAGS=-Wall -Wextra -Werror

# Name of your executable
NAME=libft.a

# Source and object files
SRC=ft_isascii.c ft_memset.c ft_isdigit.c ft_strlen.c \
    ft_bzero.c ft_isprint.c ft_isalnum.c ft_memcpy.c \
    ft_isalpha.c ft_memmove.c

OBJ=$(SRC:.c=.o)

# Default target
all: $(NAME)

# Rule for building the final executable
$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ)

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

