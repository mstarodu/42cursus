GREEN		:= \033[0;32m
YELLOW		:= \033[0;33m
NC		:= \033[0m
DASHES		:= ---------

CC 		:= cc
CFLAGS		:= -Wall -Wextra -Werror
GNLFLAGS	:= -D BUFFER_SIZE=23

ifeq ($(DEBUG),yes)
$(CFLAGS) += -g
endif

NAME		:= get_next_line.out
GNL_FILES	:= get_next_line.c get_next_line_utils.c
GNL_PATH	:= ../../get_next_line
GNL_PATHS	:= $(addprefix $(GNL_PATH)/,$(GNL_FILES))

all: $(NAME)

$(NAME):
	$(CC) $(CFLAGS) $(GNLFLAGS) get_next_line.c -o $(NAME) $(GNL_PATHS)
	@echo "$(GREEN)$(DASHES) get_next_line testing function is compiled$(NC)"

clean:

fclean: clean
	rm -f $(wildcard *.out)
	@echo "$(YELLOW)$(DASHES) get_next_line fclean is done$(NC)"

re: fclean all

run:
	clear
	./$(NAME) get_next_line.txt

.PHONY: all re clean fclean
