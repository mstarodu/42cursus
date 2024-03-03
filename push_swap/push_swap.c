/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstarodu <mstarodu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 14:04:18 by mstarodu          #+#    #+#             */
/*   Updated: 2024/03/03 23:07:32 by mstarodu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include  "push_swap.h"

size_t	st_strlen(t_string s)
{
	size_t	len;

	if (s == NULL)
		return (0);
	len = 0;
	while (s[len])
		++len;
	return (len);
}

int	st_strcmp(t_string a, t_string b)
{
	while (*a && *a == *b)
	{
		++a;
		++b;
	}
	return (*a - *b);
}

int	check_dup(t_string argv[])
{
	int	i;
	int	j;

	i = 1;
	while (argv[i+1])
	{
		j = i + 1;
		while (argv[j])
		{
			if (st_strcmp(argv[i], argv[j++]) == 0)
				return (FAIL);
		}
		++i;
	}
	return (OK);
}

int	st_putstr_fd(t_string s, int fd)
{
	if (write(fd, s, st_strlen(s)) == FAIL)
		return (FAIL);
	return (OK);
}

int	st_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (TRUE);
	return (FALSE);
}

int	st_isspace(char c)
{
	return (c == ' ' || c == '\f' || c == '\n'
		|| c == '\r' || c == '\t' || c == '\v');
}

int	st_atoi(t_string nptr, int *nbr)
{
	int		sign;
	long	lnbr;

	sign = PLUS;
	lnbr = 0;
	while (st_isspace(*nptr) == TRUE)
		nptr++;
	if (*nptr == '-' || *nptr == '+')
		if (*nptr++ == '-')
			sign = MINUS;
	if (st_isdigit(*nptr) == FALSE)
		return (FAIL);
	while (st_isdigit(*nptr) == TRUE)
		lnbr = lnbr * 10 + (*nptr++ - '0');
	lnbr *= sign;
	if (lnbr < INT_MIN || lnbr > INT_MAX)
		return (FAIL);
	*nbr = (int) lnbr;
	return (OK);
}

int	create_node(t_node **node, int nbr)
{
	*node = (t_node *) malloc(sizeof(t_node));
	if (*node == NULL)
		return (FAIL);
	(*node)->nbr = nbr;
	(*node)->next = NULL;
	(*node)->prev = NULL;
	return (OK);
}

int	create_stacks(t_list *a, t_list *b)
{
	a->head = NULL;
	a->tail = NULL;
	b->head = NULL;
	b->tail = NULL;
	return (OK);
}

void	append_node(t_list *stack, t_node *node)
{
	if (stack->head == NULL)
	{
		node->prev = NULL;
		stack->head = node;
	}
	else
	{
		stack->tail->next = node;
		node->prev = stack->tail;
	}
	node->next = NULL;
	stack->tail = node;
}


int	collect_arguments(t_string argv[], t_list *a)
{
	int		nbr;
	int		i;
	t_node	*node;

	if (check_dup(argv) == FAIL)
		return (FAIL);
	i = 1;
	while (argv[i])
	{
		if (st_atoi(argv[i], &nbr) == FAIL || create_node(&node, nbr) == FAIL)
			return (FAIL);
		append_node(a, node);
		++i;
	}
	return (OK);
}

void	st_putnbr_fd(int n, int fd)
{
	char	chr;

	chr = 0;
	if (n == -2147483648)
		write(fd, "-2147483648", 11);
	else if (n < 0)
	{
		write(fd, "-", 1);
		st_putnbr_fd(-n, fd);
	}
	else if (n < 10)
	{
		chr = n + '0';
		write(fd, &chr, 1);
	}
	else
	{
		st_putnbr_fd(n / 10, fd);
		chr = n % 10 + '0';
		write(fd, &chr, 1);
	}
}

void	swap(t_list *stack, char name)
{
	int	t;

	if (stack->head == NULL || stack->head->next == NULL)
		return ;
	t = stack->head->nbr;
	stack->head->nbr = stack->head->next->nbr;
	stack->head->next->nbr = t;
	if (name == 'a')
		st_putstr_fd("sa\n", STDOUT_FILENO);
	else if (name == 'b')
		st_putstr_fd("sb\n", STDOUT_FILENO);
}

void	swap_swap(t_list *a, t_list *b)
{
	swap(a, 0);
	swap(b, 0);
	st_putstr_fd("ss\n", STDOUT_FILENO);
}

t_node	*shift(t_list *stack)
{
	t_node *shifted;

	shifted = stack->head;
	if (shifted != NULL)
	{
		if (stack->head->next == NULL)
		{
			stack->head = NULL;
			stack->tail = NULL;
		}
		else
		{
			stack->head = stack->head->next;
			stack->head->prev = NULL;
		}
	}
	return (shifted);
}

void	unshift(t_list *stack, t_node *new)
{
	if (new == NULL)
		return ;
	if (stack->head == NULL)
	{
		new->next = NULL;
		new->prev = NULL;
		stack->head = new;
		stack->tail = new;
	}
	else
	{
		new->next = stack->head;
		new->prev = NULL;
		stack->head = new;
	}
}

void	push(char name, t_list *a, t_list *b)
{
	if (name == 'a')
	{
		unshift(a, shift(b));
		st_putstr_fd("pa\n", STDOUT_FILENO);
	}
	else if (name == 'b')
	{
		unshift(b, shift(a));
		st_putstr_fd("pb\n", STDOUT_FILENO);
	}
}

void	rotate(t_list *stack, char name)
{
	if (stack->head == NULL || stack->head == stack->tail)
		return ;
	append_node(stack, shift(stack));
	if (name == 'a')
		st_putstr_fd("ra\n", STDOUT_FILENO);
	else if (name == 'b')
		st_putstr_fd("rb\n", STDOUT_FILENO);

}

void	rotate_rotate(t_list *a, t_list *b)
{
	rotate(a, 0);
	rotate(b, 0);
	st_putstr_fd("rr\n", STDOUT_FILENO);
}

t_node	*pop(t_list *stack)
{
	t_node	*popped;

	popped = stack->tail;
	if (popped != NULL)
	{
		stack->tail = stack->tail->prev;
		stack->tail->next = NULL;
	}
	return (popped);
}

void	reverse_rotate(t_list *stack, char name)
{
	if (stack->head == NULL || stack->head == stack->tail)
		return ;
	unshift(stack, pop(stack));
	if (name == 'a')
		st_putstr_fd("rra\n", STDOUT_FILENO);
	else if (name == 'b')
		st_putstr_fd("rrb\n", STDOUT_FILENO);
}

void	reverse_rotate_rotate(t_list *a, t_list *b)
{
	reverse_rotate(a, 0);
	reverse_rotate(b, 0);
	st_putstr_fd("rrr\n", STDOUT_FILENO);
}

int	check_sorted(t_list *stack)
{
	t_node	*i;
	t_node	*j;

	if (stack->head == NULL || stack->head->next == NULL)
		return (TRUE);
	i = stack->head;
	j = stack->head->next;
	while (i != stack->tail)
	{
		if (i->nbr > j->nbr)
			return (FALSE);
		i = i->next;
		j = j->next;	
	}
	return (TRUE);
}

int	count_nodes(t_list *stack)
{
	t_node	*n;
	int	i;

	i = 0;
	n = stack->head;
	while (n != NULL)
	{
		++i;
		n = n->next;
	}
	return (i);
}

void	sort_three_nodes(t_list *stack, char name)
{
	int	top;
	int	mid;
	int	btm;

	if (stack->head == NULL || stack->head->next == NULL || stack->head->next->next == NULL)
		return ;

	while (check_sorted(stack) == FALSE)
	{
		top = stack->head->nbr;
		mid = stack->head->next->nbr;
		btm = stack->head->next->next->nbr;
		if ((top > mid && btm > top) || (mid > top && mid > btm))
			swap(stack, name);
		else if (top > btm && mid > top)
			reverse_rotate(stack, name);
		else
			rotate(stack, name);
	}
}

void	insertion_sort(t_list *a, t_list *b)
{
	int	nbr;
	int	plc;
	int	i;
	t_node	*node;

	if (count_nodes(a) == 3)
		sort_three_nodes(a, 'a');
	else
	{
		nbr = a->head->nbr;
		plc = 0;
		i = 0;
		node = a->head;
		while (node != NULL)
		{
			if (node->nbr < nbr)
			{
				nbr = node->nbr;
				plc = i;
			}
			++i;
			node = node->next;
		}
		if (count_nodes(a)/2 >= plc)
			plc = TOP;
		else
			plc = BOTTOM;
		while (a->head->nbr != nbr)
		{
			if (plc == TOP)
				rotate(a, 'a');
			else
				reverse_rotate(a, 'a');
		}
		push('b', a, b);
	}
}

void	free_stack(t_list *stack)
{
	t_node	*current_node;
	t_node	*next_node;

	current_node = stack->head;
	while (current_node != NULL)
	{
		next_node = current_node->next;
		free(current_node);
		current_node = next_node;
	}
	stack->head = NULL;
	stack->tail = NULL;
}


int	free_stacks(t_list *a, t_list *b, int result)
{
	if (a != NULL)
		free_stack(a);
	if (b != NULL)
		free_stack(b);
	if (result == FAIL)
		st_putstr_fd("Error\n", STDERR_FILENO);
	return (result);
}

// Service
void	print_list(t_list *stack, t_string name)
{
	t_node	*current_node;

	current_node = stack->head;
	st_putstr_fd(name, STDOUT_FILENO);
	while (current_node != NULL)
	{
		st_putnbr_fd(current_node->nbr, STDOUT_FILENO);
		write(STDOUT_FILENO, "\n", 1);
		current_node = current_node->next;
	}
	st_putstr_fd("---\n", STDOUT_FILENO);
}

#include <stdio.h>
int	main(int argc, char *argv[])
{
	t_list	a;
	t_list	b;
	int	args;

	args = argc - 1;
	if (args < 1)
		return (FAIL);
	if (create_stacks(&a, &b) == FAIL || collect_arguments(argv, &a) == FAIL)
		return (free_stacks(&a, &b, FAIL));
	if (check_sorted(&a) == TRUE)
		return (free_stacks(&a, &b, OK));
	// print_list(&a, "Start Stack A\n");
	// Conditions
	if (args == 2)
		swap(&a, 'a');
	else if (args == 3)
		sort_three_nodes(&a, 'a');
	else if (args <= 6) // insertion sort + condition check
	{
		while (check_sorted(&a) == FALSE)
			insertion_sort(&a, &b);
		while (b.head != NULL)
			push('a', &a, &b);
	}
	else if (args < 100) // quick sort
	{}
	else if (args >= 100) // radix sort
	{}
	// printf("---\n");
	// print_list(&a, "Stack A\n");
	// print_list(&b, "Stack B\n");
	return (free_stacks(&a, &b, OK));
}
