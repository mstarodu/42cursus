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

void	my_printlst(t_list *lst, char *str)
{
	t_list	*ptrlst;

	printf("List: %s\n", str);
	ptrlst = lst;
	while (ptrlst != NULL)
	{
		printf("%2i\n", *((int *)ptrlst->content));
		ptrlst = ptrlst->next;
	}
	ft_lstclear(&lst, free);
	return ;
}

int		my_loadargs(int argc, char **argv, t_list **lst);
void	my_lstsort(int argc, t_list **lst_a, t_list **lst_b);

int	main(int argc, char *argv[])
{
	t_list	*a;
	t_list	*b;

	a = NULL;
	b = NULL;

	my_loadargs(argc, argv, &a);
	my_lstsort(argc, &a, &b);
	return (0);
}

int	my_loadargs(int argc, char **argv, t_list **lst)
{
	int		*iptr;
	t_list	*new;

	if (argc-- < 2)
		exit(0);
	while (argc > 0)
	{
		if (my_atoip(argv[argc], &iptr) != 0)
			my_puterr(2, *lst, NULL);
		new = ft_lstnew(iptr);
		if (new == NULL)
			my_puterr(3, *lst, iptr);
		ft_lstadd_front(lst, new);
		--argc;
	}
	if (my_hasdup(*lst))
		my_puterr(4, *lst, NULL);
	return (0);
}

void	my_lstsort(int argc, t_list **a, t_list **b)
{
	(void)argc;
	my_rotate(a);
	my_rotate(a);
	my_reverse_rotate(a);
	my_reverse_rotate(a);
	// printf("Sorted?: %i\n", ft_lstsorted(*a, 'D'));
	my_printlst(*a, "a");
	my_printlst(*b, "b");
	return ;
}


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
