/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstarodu <mstarodu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 14:04:18 by mstarodu          #+#    #+#             */
/*   Updated: 2024/02/06 18:02:12 by mstarodu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <limits.h>
#define DUMMY 0
#define PLUS 1
#define MINUS -1
#define OK 0
#define FAIL -1
#define TRUE 1
#define FALSE 0

typedef int	t_result;
typedef int	t_bool;
typedef char*	t_string;

typedef struct s_node
{
	int				nbr;
	struct s_node	*next;
}	t_node;

typedef struct s_stack
{
	t_node	*head;
	t_node	*tail;
}	t_stack;

// Check is the list has duplicates

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

t_result	create_stacks(t_stack *a, t_stack *b)
{
	if (create_node(&a->head, DUMMY) == FAIL || create_node(&b->head, DUMMY) == FAIL)
		return (FAIL);
	a->tail = a->head;
	b->tail = b->head;
	return (OK);
}

void	append_node(t_stack *stack, t_node *node)
{
	stack->tail->next = node;
	stack->tail = node;
}

void	free_stack(t_stack *stack)
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

t_result	free_stacks(t_stack *a, t_stack *b, t_result status)
{
	free_stack(a);
	if (b != NULL)
		free_stack(b);
	if (status == FAIL)
		st_putstr_fd("Error\n", STDERR_FILENO);
	else
		st_putstr_fd("OK! - TO DELETE\n", STDOUT_FILENO);
	return (status);
}

int	collect_arguments(char *argv[], t_stack *a)
{
	int		nbr;
	int		i;
	t_node	*node;

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

void	print_stack(t_stack *stack, t_string name)
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

int	main(int argc, char *argv[])
{
	t_stack	a;
	t_stack	b;

	if (argc < 2 || create_stacks(&a, &b) == FAIL
		|| collect_arguments(argv, &a) == FAIL)
		return (free_stacks(&a, &b, FAIL));
	print_stack(&a, "Stack A\n");
	print_stack(&b, "Stack B\n");
	return (free_stacks(&a, &b, OK));
}
