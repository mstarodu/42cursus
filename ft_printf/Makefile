CC := cc
CFLAGS := -Wall -Wextra -Werror
LIBFT_DIR := ./libft
LIBFT := $(LIBFT_DIR)/libft.a
NAME := libftprintf.a
SRCS := ft_printf.c print_c.c print_nbr.c print_str.c
LIBFT_SRCS := ft_atoi.c ft_isascii.c ft_memcmp.c ft_putendl_fd.c ft_strdup.c ft_strlen.c ft_strtrim.c \
       ft_bzero.c ft_isdigit.c ft_memcpy.c ft_putnbr_fd.c ft_striteri.c ft_strmapi.c ft_substr.c \
       ft_calloc.c ft_isprint.c ft_memmove.c ft_putstr_fd.c ft_strjoin.c ft_strncmp.c ft_tolower.c \
       ft_isalnum.c ft_itoa.c ft_memset.c ft_split.c  ft_strlcat.c ft_strnstr.c ft_toupper.c \
       ft_isalpha.c ft_memchr.c ft_putchar_fd.c ft_strchr.c ft_strlcpy.c ft_strrchr.c
LIBFT_SRCS := $(addprefix libft/,$(LIBFT_SRCS))

OBJS := $(SRCS:.c=.o)
LIBFT_OBJS := $(LIBFT_SRCS:.c=.o)

all: libft $(NAME)

libft: 
	$(MAKE) -C $(LIBFT_DIR)

$(NAME): $(OBJS) $(LIBFT)
	ar rcs $(NAME) $(OBJS) $(LIBFT_OBJS)

%.o : %.c ft_printf.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	rm -f $(OBJS)

fclean: clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	rm -f $(NAME)

re: fclean all

.PHONY: libft all clean fclean re
