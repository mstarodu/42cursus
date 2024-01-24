CC 		:= cc
CFLAGS		:= -Wall -Wextra -Werror -g

FT_PRINTF	:= ft_printf.out
LIBFTPRINTF_DIR	:= ../ft_printf
LIBFTPRINTF	:= $(LIBFTPRINTF_DIR)/libftprintf.a
FT_PRINTF_SRCS	:= ft_printf.c
FT_PRINTF_OBJS	:= $(FT_PRINTF_SRCS:.c=.o )

GNL_NAME	:= get_next_line.out
GNL_FILES	:= get_next_line.c get_next_line_utils.c
GNL_PATH	:= ../get_next_line
GNL_PATHS	:= $(addprefix $(GNL_PATH)/,$(GNL_FILES))
GNL_LIBFT_DIR	:= $(GNL_PATH)/libft
GNL_LIBFT_SRCS := ft_atoi.c ft_isascii.c ft_memcmp.c ft_putendl_fd.c ft_strdup.c ft_strlen.c ft_strtrim.c \
       ft_bzero.c ft_isdigit.c ft_memcpy.c ft_putnbr_fd.c ft_striteri.c ft_strmapi.c ft_substr.c \
       ft_calloc.c ft_isprint.c ft_memmove.c ft_putstr_fd.c ft_strjoin.c ft_strncmp.c ft_tolower.c \
       ft_isalnum.c ft_itoa.c ft_memset.c ft_split.c  ft_strlcat.c ft_strnstr.c ft_toupper.c \
       ft_isalpha.c ft_memchr.c ft_putchar_fd.c ft_strchr.c ft_strlcpy.c ft_strrchr.c
GNL_LIBFT_SRCS := $(addprefix $(GNL_LIBFT_DIR)/,$(GNL_LIBFT_SRCS))
GNL_LIBFT_OBJS := $(GNL_LIBFT_SRCS:.c=.o)

all: ft_printf get_next_line

ft_printf: lftprintf $(FT_PRINTF_OBJS)
	$(CC) $(CFLAGS) $(FT_PRINTF_OBJS) -o $(FT_PRINTF) $(LIBFTPRINTF)

lftprintf:
	$(MAKE) -C $(LIBFTPRINTF_DIR)

get_next_line: lft $(GNL_LIBFT_OBJS)
	$(CC) $(CFLAGS) get_next_line.c -o $(GNL_NAME) $(GNL_PATHS) $(GNL_LIBFT_OBJS)

lft:
	$(MAKE) -C $ $(GNL_LIBFT_DIR)

clean:
	rm -f $(wildcard *.o)
	$(MAKE) clean -C $(LIBFTPRINTF_DIR)
	$(MAKE) clean -C $(GNL_LIBFT_DIR)

fclean: clean
	rm -f $(wildcard *.out)
	$(MAKE) fclean -C $(LIBFTPRINTF_DIR)
	$(MAKE) fclean -C $(GNL_LIBFT_DIR)

re: fclean all

.PHONY: all get_next_line ft_printf libs re clean fclean
