RED		:= \033[0;31m
GREEN		:= \033[0;32m
NC		:= \033[0m
DASHES		:= ---------

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

$(NAME): lftprintf $(FT_PRINTF_OBJS) 
	$(CC) $(CFLAGS) $(FT_PRINTF_OBJS) -o $(NAME) $(LIBFTPRINTF)
	@echo "$(GREEN)$(DASHES) Testing function is compiled$(NC)"

lftprintf:
	$(MAKE) -C $(LIBFTPRINTF_DIR)
	@echo "$(GREEN)$(DASHES) lftprinf is done$(NC)"

clean:
	rm -f $(wildcard *.o)
	$(MAKE) clean -C $(LIBFTPRINTF_DIR)
	@echo "$(RED)$(DASHES) clean is done$(NC)"

fclean: clean
	rm -f $(wildcard *.out)
	$(MAKE) fclean -C $(LIBFTPRINTF_DIR)
	@echo "$(RED)$(DASHES) fclean is done$(NC)"

re: fclean all

run: all
	clear
	@./$(NAME)
	@echo "$(RED)$(DASHES) Testing function is executed$(NC)"

.PHONY: all re clean fclean
