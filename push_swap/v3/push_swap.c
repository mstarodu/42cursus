/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstarodu <mstarodu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 14:04:18 by mstarodu          #+#    #+#             */
/*   Updated: 2024/06/09 08:49:46y mstarodu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#include <stdio.h>

void	ft_printstck(t_list *stck)
{
	while (stck != NULL)
	{
		printf("%2i\n", *((int *)stck->content));
		stck = stck->next;
	}
	return ;
}

int	ft_puterr(int err, t_list *stck, int *iptr)
{
	if (stck != NULL)
		ft_lstclear(&stck, free);
	if (iptr != NULL)
		free(iptr);
	write(STDERR_FILENO, "Error\n", 6);
	exit (err);
}

int	ft_loadargs(int argc, char **argv, t_list **stck)
{
	int		*iptr;
	t_list	*new;

	if (argc-- < 2)
		exit(0);
	while (argc > 0)
	{
		if (ft_atoip(argv[argc], &iptr) != 0)
			ft_puterr(2, *stck, NULL);
		new = ft_lstnew(iptr);
		if (new == NULL)
			ft_puterr(3, *stck, iptr);
		ft_lstadd_back(stck, new);
		--argc;
	}
	if (ft_hasdup(*stck))
		ft_puterr(4, *stck, NULL);
	return (0);
}


int	main(int argc, char *argv[])
{
	t_list	*stck_a;
	// t_list	*stck_b;

	stck_a = NULL;
	// stck_b = NULL;

	ft_loadargs(argc, argv, &stck_a);
	ft_printstck(stck_a);
	// ft_sortstck(&stck_a, &stck_b);
	return (0);
}

/*
# List of tasks:
- [ ] args as one argument
- [ ] args as arguments
- [ ] ascending order into stack a
- [ ] no memory leaks
- [ ] makefile rules
- [ ] no relink
- [ ] first arg on top of the stack
- [ ] instructions separated by \n
- [ ] no arguments - promt back
- [ ] error, "Error\n" on the standard error
	- [ ] some arguments aren’t integers
	- [ ] some arguments are bigger than an integer
	- [ ] there are duplicates

*/
