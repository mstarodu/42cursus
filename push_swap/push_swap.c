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
#define	OK 0
#define FAIL -1
#define TRUE 1
#define FALSE 0

typedef int t_status
typedef int t_bool

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
// Check if atoi is succsesful

size_t	st_strlen(char *s)
{
	size_t	len;

	if (s == NULL)
		return (0);
	len = 0;
	while (s[len])
		++len;
	return (len);
}

t_status	st_putstr_fd(char *s, int fd)
{
	if (write(fd, s, ft_strlen(s)) == FAIL)
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

t_status	st_atoi(const char *nptr, int *nbr)
{
	int	sign;
	long	lnbr;
	
	sign = PLUS;
	lnbr = 0;
	while (ft_isspace(*nptr) == TRUE)
		nptr++;
	if (*nptr == '-' || *nptr == '+')
		if (*nptr++ == '-')
			sign = MINUS;
	if (ft_isdigit(*nptr) == FALSE)
		return (FAIL);
	while (ft_isdigit(*nptr) == TRUE)
		lnbr = lnbr * 10 + (*nptr++ - '0');
	if (lnbr < INT_MIN && lnbr > INT_MAX)
		return (FAIL);
	*nbr = (int) lnbr * sign;
	return (OK);
}

t_status	*create_node(t_node *node, int nbr)
{
	node = (t_node *) malloc(sizeof(t_node));
	if (node == NULL)
		return (st_putstr_fd("Error\n", STDERR_FILENO), FAIL);
	node->nbr = nbr;
	node->next = NULL;
	return (OK);
}

t_status	create_stacks(t_stack *a, t_stack *b)
{
	t_node	*tmp;

	if (create_node(tmp, DUMMY) = FAIL)
		return (ft_putstr_fd("Error\n", STDERR_FILENO), FAIL);
	a->head = tmp;
	a->tail = tmp;
	if (create_node(tmp, DUMMY) = FAIL)
		return (free(a->head), ft_putstr_fd("Error\n", STDERR_FILENO), FAIL);
	b->head = tmp;
	b->tail = tmp;
	return (OK);
}

void	append_node(t_stack *stack, t_node *node)
{
	stack->tail->next = node;
	stack->tail = node;
}

// free all stacks on fail
void	free_stack(t_stack *stack)
{
	t_stack	*p;

	while (stack->head->next != NULL)
	{
		p = stack->head->next;
		free(stack->head);
		stack->head = p;
	}
	free (stack->tail);
}

int	collect_arguments(char *argv[], t_stack *a)
{
	int	nbr;
	t_node	node;

	nbr = 0;
	while (*argv)
	{
		if (st_atoi(*arg, &nbr) == FAIL)
			return (FAIL);
		if (create_node(&node, &nbr) == FAIL)
			return (FAIL);

		append_node();
		++argv;
	}
}

int	main(int argc, char *argv[])
{
	t_stack	a;
	t_stack	b;

	if (create_stacks(&a, &b) == 0 || collect_arguments(argv[], &a) == 0)
		return (1);
	return (ft_putstr_fd("OK!\n", STDOUT_FILENO), 0);
}
