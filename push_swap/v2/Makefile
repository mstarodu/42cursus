.PHONY: test1 test2 all

all: test1 test2

test1:
	@echo "Running test1..."
	@./a.out 1 4 3 5 6 | wc -l

test2:
	@echo "Running test2..."
	@./a.out 1 4 7 5 6 | wc -l


1 2 3 4 5 6
2 3 4 5 6 1
3 4 5 6 1 2
4 5 6 1 2 3
5 6 1 2 3 4
6 1 2 3 4 5

