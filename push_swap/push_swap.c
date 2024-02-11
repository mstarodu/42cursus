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
#define DUMMY 0

typedef struct s_node
{
	int				nbr;
	struct s_node	*next;
}	t_node;

// Check is the list has duplicates
// Check if atoi is succsesful

t_node	*create_node(int nbr)
{
	t_node	*n;

	n = (t_node *) malloc(sizeof(t_node));
	if (n == NULL)
		return (NULL);
	n->nbr = nbr;
	n->next = NULL;
	return (n);
}

size_t	ft_strlen(char *s)
{
	size_t	l;

	if (s == NULL)
		return (0);
	l = 0;
	while (s[l])
		++l;
	return (l);
}

void	ft_putstr_fd(char *s, int fd)
{
	write(fd, s, ft_strlen(s));
}

int	create_stacks(t_node **a, t_node **b)
{
	*a = create_node(DUMMY);
	*b = create_node(DUMMY);
	if (a == NULL)
		return (ft_putstr_fd("Error\n", STDERR_FILENO), 0);
	if (b == NULL)
		return (free(a), ft_putstr_fd("Error\n", STDERR_FILENO), 0);
	return (1);
}

int	main(int argc, char *argv[])
{
	t_node	*a;
	t_node	*b;

	a = NULL;
	b = NULL;
	if (create_stacks(&a, &b) == 0)
		return (1);
	ft_putstr_fd("OK!\n", STDOUT_FILENO);
	return (0);
}
