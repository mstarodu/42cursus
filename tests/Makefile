CC 		:= cc
CFLAGS		:= -Wall -Wextra -Werror -g

FT_PRINTF	:= ft_printf.out
LIBFTPRINTF_DIR	:= ../ft_printf
LIBFTPRINTF	:= $(LIBFTPRINTF_DIR)/libftprintf.a
FT_PRINTF_SRCS	:= ft_printf.c
FT_PRINTF_OBJS	:= $(FT_PRINTF_SRCS:.c=.o )

GNL_NAME	:= get_next_line.out
GNL_FILES	:= get_next_line.c
GNL_PATH	:= ../get_next_line
GNL_PATHS	:= $(addprefix $(GNL_PATH)/,$(GNL_FILES))

all: ft_printf get_next_line

ft_printf: lftprintf $(FT_PRINTF_OBJS)
	$(CC) $(CFLAGS) $(FT_PRINTF_OBJS) -o $(FT_PRINTF) $(LIBFTPRINTF)

lftprintf:
	$(MAKE) -C $(LIBFTPRINTF_DIR)

get_next_line:
	$(CC) $(CFLAGS) get_next_line.c -o $(GNL_NAME) $(GNL_PATHS)

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
