CC 		:= cc
CFLAGS		:= -Wall -Wextra -Werror

LIBFT_DIR	:= ../Libft

FT_PRINTF	:= ft_printf.out
LIBFTPRINTF_DIR	:= ../ft_printf
LIBFTPRINTF	:= $(LIBFTPRINTF_DIR)/libftprintf.a
FT_PRINTF_SRCS	:= ft_printf.c
FT_PRINTF_OBJS	:= $(FT_PRINTF_SRCS:.c=.o )

all: ft_printf

ft_printf: lftprintf $(FT_PRINTF_OBJS)
	$(CC) $(CFLAGS) $(FT_PRINTF_OBJS) -o $(FT_PRINTF) $(LIBFTPRINTF)

lftprintf:
	$(MAKE) -C $(LIBFTPRINTF_DIR)

clean:
	rm -f $(wildcard *.o)
	$(MAKE) clean -C $(LIBFTPRINTF_DIR)
	$(MAKE) clean -C $(LIBFT_DIR)

fclean: clean
	rm -f $(wildcard *.out)
	$(MAKE) fclean -C $(LIBFTPRINTF_DIR)
	$(MAKE) fclean -C $(LIBFT_DIR)

re: fclean all

.PHONY: all ft_printf libs re clean fclean
