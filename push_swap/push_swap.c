/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstarodu <mstarodu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 14:04:18 by mstarodu          #+#    #+#             */
/*   Updated: 2024/02/25 23:42:10 by mstarodu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include  "push_swap.h"

// Check is the list has duplicates
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

t_result	st_putstr_fd(t_string s, int fd)
{
	if (write(fd, s, st_strlen(s)) == FAIL)
		return (FAIL);
	return (OK);
}

t_bool	st_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (TRUE);
	return (FALSE);
}

t_bool	st_isspace(char c)
{
	return (c == ' ' || c == '\f' || c == '\n'
		|| c == '\r' || c == '\t' || c == '\v');
}

t_result	st_atoi(t_string nptr, int *nbr)
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

t_result	create_node(t_node **node, int nbr)
{
	*node = (t_node *) malloc(sizeof(t_node));
	if (*node == NULL)
		return (FAIL);
	(*node)->nbr = nbr;
	(*node)->next = NULL;
	return (OK);
}

t_result	create_stacks(t_list *a, t_list *b)
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

int	check_dup(t_string *splitted)
{
	int	i;
	int	j;

	i = 0;
	while (splitted[i+1])
	{
		j = i + 1;
		while (splitted[j])
		{
			if (st_strcmp(splitted[i], splitted[j++]) == 0)
				return (FAIL);
		}
		++i;
	}
	return (OK);
}

t_result	free_stacks(t_list *a, t_list *b, t_result result)
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

t_result	collect_arguments(t_string argv, t_list *a)
{
	int		nbr;
	int		i;
	t_node	*node;
	t_string	*splitted;

	splitted = NULL;
	if (st_split(argv, ' ', &splitted) == FAIL || check_dup(splitted) == FAIL)
		return (free(splitted), FAIL);
	i = 0;
	while (splitted[i])
	{
		if (st_atoi(splitted[i], &nbr) == FAIL || create_node(&node, nbr) == FAIL)
			return (free(splitted), FAIL);
		append_node(a, node);
		++i;
	}
	return (free(splitted), OK);
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

void	swap_swap(t_list *a, t_list *b)
{
	swap(a);
	swap(b);
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

void	rotate_rotate(t_list *a, t_list *b)
{
	rotate(a);
	rotate(b);
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

void	reverse_rotate_rotate(t_list *a, t_list *b)
{
	reverse_rotate(a);
	reverse_rotate(b);
}

#include <stdio.h>
int	main(int argc, char *argv[])
{
	t_list	a;
	t_list	b;

	if (argc < 2)
		return (FAIL);
	if (create_stacks(&a, &b) == FAIL
		|| collect_arguments(argv[1], &a) == FAIL)
		return (free_stacks(&a, &b, FAIL));
	print_list(&a, "Stack A\n");
	printf("a head: %p ===== a tail: %p\n", a.head, a.tail);

	swap(&a);	
	push(&a, &b);
	push(&a, &b);
	push(&a, &b);
	rotate_rotate(&a, &b);
	reverse_rotate_rotate(&a, &b);
	swap(&a);	
	push(&b, &a);
	push(&b, &a);
	push(&b, &a);
		

	print_list(&a, "Stack A\n");
	print_list(&b, "Stack B\n");
	printf("a head: %p ===== a tail: %p\n", a.head, a.tail);
	printf("b head: %p ===== b tail: %p\n", b.head, b.tail);
	return (free_stacks(&a, &b, OK));
}
