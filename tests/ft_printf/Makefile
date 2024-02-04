RED		:= \033[0;31m
GREEN		:= \033[0;32m
NC		:= \033[0m

CC 		:= cc
CFLAGS		:= -Wall -Wextra -Werror

ifeq ($(DEBUG),yes)
CFLAGS	+= -g
endif

NAME		:= ft_printf.out
LIBFTPRINTF_DIR	:= ../../ft_printf
LIBFTPRINTF	:= $(LIBFTPRINTF_DIR)/libftprintf.a
FT_PRINTF_SRCS	:= ft_printf.c
FT_PRINTF_OBJS	:= $(FT_PRINTF_SRCS:.c=.o)

all: $(NAME)

$(NAME): lftprintf
	@echo "$(GREEN)Compliling ft_printf testing main$(NC)"
	$(CC) $(CFLAGS) $(FT_PRINTF_OBJS) -o $(NAME) $(LIBFTPRINTF)

lftprintf:
	@echo "$(GREEN)Making inside ft_printf$(NC)"
	$(MAKE) -C $(LIBFTPRINTF_DIR)

clean:
	@echo "$(RED)Cleaning .o files$(NC)"
	rm -f $(wildcard *.o)
	@echo "$(RED)Executing clean inside ft_printf folder$(NC)"
	$(MAKE) clean -C $(LIBFTPRINTF_DIR)

fclean: clean
	@echo "$(RED)Cleaning the .out file$(NC)"
	rm -f $(wildcard *.out)
	@echo "$(RED)Executing fclean inside ft_printf folder$(NC)"
	$(MAKE) fclean -C $(LIBFTPRINTF_DIR)

re: fclean all

run: all
	clear
	@./$(NAME)

.PHONY: all re clean fclean
