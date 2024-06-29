500TO0 := $(shell seq 500 -1 0)
0TO500 := $(shell seq -1 500)
RND500 := $(shell seq -1 500 | shuf)
RND100 := $(shell seq -1 100 | shuf)
RND10 := $(shell seq -1 10 | shuf)

test: all
	clear
	./push_swap 4 67 3

all:
	cc -Wall -Werror -Werror -g my_ascii_to_int_ptr.c ft_isdigit.c ft_lstadd_front.c ft_lstdelone.c \
	ft_lstnew.c ft_strdup.c push_swap.h ft_lstadd_back.c \
	ft_lstclear.c  ft_lstlast.c ft_lstsize.c push_swap.c ft_strlen.c \
	my_lst_has_dup.c ft_lstmap.c my_put_err.c operations.c my_lst_sorted.c my_find_position.c \
	my_lst_find_extremum.c -o push_swap
ssa:
	@echo 'Random 500'
	./a.out $(RND500)
	@echo 'Random 100'
	./a.out $(RND100)

all2:
	cc -Wall -Werror -Werror -g my_ascii_to_int_ptr.c ft_isdigit.c ft_lstadd_front.c ft_lstdelone.c \
	ft_lstnew.c ft_strdup.c push_swap.h ft_lstadd_back.c \
	ft_lstclear.c  ft_lstlast.c ft_lstsize.c push_swap.c ft_strlen.c \
	my_lst_has_dup.c ft_lstmap.c my_put_err.c operations.c my_lst_sorted.c my_find_position.c \
	my_lst_find_extremum.c