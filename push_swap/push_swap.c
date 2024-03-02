/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstarodu <mstarodu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 14:04:18 by mstarodu          #+#    #+#             */
/*   Updated: 2024/03/02 16:21:07 by mstarodu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include  "push_swap.h"

// Check is no  letters (fix atoi)
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
	if (stack->tail != NULL)
		stack->tail->next = node;
	else
		stack->head = node;
	stack->tail = node;
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

int	free_stacks(t_list *a, t_list *b, int result)
{
	if (a != NULL)
		free_stack(a);
	if (b != NULL)
		free_stack(b);
	if (result == FAIL)
		st_putstr_fd("Error\n", STDERR_FILENO);
	else
		st_putstr_fd("OK! - TO DELETE\n", STDOUT_FILENO);
	return (result);
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

void	swap(t_list *stack)
{
	t_node	*first;
	t_node	*second;

	if (stack->head == NULL || stack->head->next == NULL)
		return ;
	first = stack->head;
	second = first->next;
	first->next = second->next;
	second->next = first;
	stack->head = second;
	if (stack->tail == second)
		stack->tail = first;
}

void	sa(t_list *stack)
{
	swap(stack);
	st_putstr_fd("sa\n", STDOUT_FILENO);
}

void	sb(t_list *stack)
{
	swap(stack);
	st_putstr_fd("sb\n", STDOUT_FILENO);
}

void	swap_swap(t_list *a, t_list *b)
{
	swap(a);
	swap(b);
	st_putstr_fd("ss\n", STDOUT_FILENO);
}

void	push(t_list *from, t_list *to)
{
	t_list	temp;

	if (from->head == NULL)
		return ;
	if (to->head == NULL && from->head == from->tail)
	{
		to->head = from->head;
		to->tail = to->head;
		from->head = NULL;
	}
	else if (to->head == NULL && from->head != from->tail)
	{
		to->head = from->head;
		to->tail = to->head;
		from->head = from->head->next;
		to->head->next = NULL;
	}
	else if (to->head == to->tail && from->head == from->tail)
	{
		temp.head = from->head;
		from->head = NULL;
		from->tail = NULL;
		to->head = temp.head;
		to->head->next = to->tail;
	}
	else if (to->head != to->tail && from->head != from->tail)
	{
		temp.head = from->head;
		from->head = from->head->next;
		temp.tail = to->head;
		to->head = temp.head;
		to->head->next = temp.tail;
	}
	else if (to->head == to->tail && from->head != from->tail)
	{
		temp.head = from->head;
		from->head = from->head->next;
		to->head = temp.head;
		to->head->next = to->tail;
	}
	else if (to->head != to->tail && from->head == from->tail)
	{
		temp.head = to->head;
		to->head = from->head;
		to->head->next = temp.head;
		from->head = NULL;
		from->tail = NULL;
	}
}

void	pa(t_list *from, t_list *to)
{
	push(from, to);
	st_putstr_fd("pa\n", STDOUT_FILENO);
}

void	pb(t_list *from, t_list *to)
{
	push(from, to);
	st_putstr_fd("pb\n", STDOUT_FILENO);
}

void	rotate(t_list *stack)
{
	t_node	*to_move;

	if (stack->head == NULL || stack->head->next == NULL)
		return ;
	to_move = stack->head;
	stack->head = stack->head->next;
	stack->tail->next = to_move;
	stack->tail = to_move;
	stack->tail->next = NULL;
}

void	ra(t_list *stack)
{
	rotate(stack);
	st_putstr_fd("ra\n", STDOUT_FILENO);
}

void	rb(t_list *stack)
{
	rotate(stack);
	st_putstr_fd("rb\n", STDOUT_FILENO);
}

void	rotate_rotate(t_list *a, t_list *b)
{
	rotate(a);
	rotate(b);
	st_putstr_fd("rr\n", STDOUT_FILENO);
}

void	reverse_rotate(t_list *stack)
{
	t_node	*lp;

	if (stack->head == NULL || stack->head->next == NULL)
		return ;
	stack->tail->next = stack->head;
	stack->head = stack->tail;
	lp = stack->head;
	while (lp->next != stack->head)
		lp = lp->next;
	lp->next = NULL;
	stack->tail = lp;
}

void	rra(t_list *stack)
{
	reverse_rotate(stack);
	st_putstr_fd("rra\n", STDOUT_FILENO);
}

void	rrb(t_list *stack)
{
	reverse_rotate(stack);
	st_putstr_fd("rrb\n", STDOUT_FILENO);
}

void	reverse_rotate_rotate(t_list *a, t_list *b)
{
	reverse_rotate(a);
	reverse_rotate(b);
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

void	sort_three_nodes(t_list *stack)
{
	while (check_sorted(stack) == FALSE)
	{
		if ((stack->head->nbr > stack->head->next->nbr && stack->tail->nbr > stack->head->nbr)
			|| (stack->head->next->nbr > stack->head->nbr && stack->head->next->nbr > stack->tail->nbr))
			sa(stack);
		else if (stack->head->nbr > stack->tail->nbr && stack->head->next->nbr > stack->head->nbr)
			rra(stack);
		else
			ra(stack);
	}
}

void	insertion_sort(t_list *a, t_list *b)
{
	int	nbr;
	int	plc;
	int	i;
	t_node	*node;

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
	node = a->head;
	if (count_nodes(a)/2 <= plc)
		plc = TOP;
	else
		plc = BOTTOM;
	while (node->nbr != nbr)
	{
		if (plc == TOP)
			ra(a);
		else
			rra(a);
		node = a->head;
	}
	pb(a, b);
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
	print_list(&a, "Start Stack A\n");
	// Conditions
	if (args == 2)
		sa(&a);
	else if (args == 3)
		sort_three_nodes(&a);
	else if (args <= 5) // insertion sort
	{
		while (a.head != NULL)
			insertion_sort(&a, &b);
	}
	else if (args < 100) // quick sort
	{}
	else if (args >= 100) // radix sort
	{}
	printf("---\n");
	print_list(&a, "Stack A\n");
	print_list(&b, "Stack B\n");
	return (free_stacks(&a, &b, OK));
}
