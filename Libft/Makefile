# Final name of the library
NAME = blah.a

# List of the c files to compile
SRCS = blah.c

# Pattern substitution
OBJECTS = $(SRC:.c=.o)

# Specify clang as a compiler for the job
CC = cc

# Specify flags to use during the compiling
CFLAGS = -Wall -Wextra -Werror

# Standard rule
all: $(NAME) 

# For all .c files generate .o files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Building the library
$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

# Prevent name confusion
.PHONY: all clean fclean re
