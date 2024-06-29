500TO0 := $(shell seq 500 -1 0)
0TO500 := $(shell seq -1 500)
RND500 := $(shell seq -1 500 | shuf)
RND100 := $(shell seq -1 100 | shuf)
RND10 := $(shell seq -1 10 | shuf)

test: all
	clear
	./push_swap 24 80 7 43 52 2 39 77 15 89 44 3 23 76 72 51 31 74 91 79 20 56 62 87 70 13 95 69 97 88 71 8 41 58 32 45 60 92 65 25 49 9 28 19 21 35 55 93 78 1 68 10 94 5 57 36 63 100 26 17 98 67 83 85 4 38 37 42 53 34 22 11 61 96 40 50 81 73 99 59 16 12 33 48 86 14 75 84 64 30 47 82 90 54 27 6 18 46 29 66

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