CC		:= cc
CFLAGS		:= -Wall -Wextra -Werror

NAME		:= libft.a

FILES		:= $(wildcard *.c)
OBJS		:= $(FILES:.c=.o)

TEST_DIR 	:= ./tests
TEST_FILES	:= $(wildcard $(TEST_DIR)/*.c)
TEST_EXE	:= $(TEST_FILES:.c=)

all: $(NAME)

$(NAME): $(OBJS)
	@echo "-----> Making Libft..."
	ar rcs $(NAME) $(OBJS)

%.o: %.c libft.h
	$(CC) $(CFLAGS) -c $< -o $@
	
mt: $(TEST_EXE)
	@echo "-----> All tests compiled"

$(TEST_EXE): % : %.c
	@echo "----->Start running $< into $@"
	$(CC) $(CFLAGS) $< -o $@
	
clean:
	rm -f $(TEST_EXE)
	rm -f $(OBJS) $(NAME)

.PHONY: clean mt
