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

void	ft_printlst(t_list *lst)
{
	t_list	*ptrlst;

	ptrlst = lst;
	while (ptrlst != NULL)
	{
		printf("%2i\n", *((int *)ptrlst->content));
		ptrlst = ptrlst->next;
	}
	ft_lstclear(&lst, free);
	return ;
}

int	ft_loadargs(int argc, char **argv, t_list **lst);

int	main(int argc, char *argv[])
{
	t_list	*lst_a;
	// t_list	*lst_b;

	lst_a = NULL;
	// lst_b = NULL;

	ft_loadargs(argc, argv, &lst_a);
	ft_printlst(lst_a);
	// ft_lstsort(argc, &stck_a, &stck_b);
	return (0);
}

int	ft_loadargs(int argc, char **argv, t_list **lst)
{
	int		*iptr;
	t_list	*new;

	if (argc-- < 2)
		exit(0);
	while (argc > 0)
	{
		if (ft_atoip(argv[argc], &iptr) != 0)
			ft_puterr(2, *lst, NULL);
		new = ft_lstnew(iptr);
		if (new == NULL)
			ft_puterr(3, *lst, iptr);
		ft_lstadd_front(lst, new);
		--argc;
	}
	if (ft_hasdup(*lst))
		ft_puterr(4, *lst, NULL);
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
- [x] no arguments - promt back
- [x] error, "Error\n" on the standard error
	- [x] some arguments aren’t integers
	- [x] some arguments are bigger than an integer
	- [x] there are duplicates

*/
