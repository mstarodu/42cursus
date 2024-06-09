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

int		ft_loadargs(int argc, char **argv, t_list **lst);
void	ft_lstsort(int argc, t_list **lst_a, t_list **lst_b);

int	main(int argc, char *argv[])
{
	t_list	*lst_a;
	t_list	*lst_b;

	lst_a = NULL;
	lst_b = NULL;

	ft_loadargs(argc, argv, &lst_a);
	// ft_printlst(lst_a);
	ft_lstsort(argc, &lst_a, &lst_b);
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

void	ft_lstsort(int argc, t_list **lst_a, t_list **lst_b)
{
	(void)argc;
	(void **)lst_a;
	(void **)lst_b;
	return ;
}

// sa (swap a): Swap the first 2 elements at the top of stack a.
// Do nothing if there is only one or no elements.
// sb (swap b): Swap the first 2 elements at the top of stack b.
// Do nothing if there is only one or no elements.
// ss : sa and sb at the same time.
// pa (push a): Take the first element at the top of b and put it at the top of a.
// Do nothing if b is empty.
// pb (push b): Take the first element at the top of a and put it at the top of b.
// Do nothing if a is empty.
// ra (rotate a): Shift up all elements of stack a by 1.
// The first element becomes the last one.
// rb (rotate b): Shift up all elements of stack b by 1.
// The first element becomes the last one.
// rr : ra and rb at the same time.
// rra (reverse rotate a): Shift down all elements of stack a by 1.
// The last element becomes the first one.
// rrb (reverse rotate b): Shift down all elements of stack b by 1.
// The last element becomes the first one.
// rrr : rra and rrb at the same time.

// 4
// 6
// 7
// 1
// 2
// 3
// 0
// -3
// 9


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
