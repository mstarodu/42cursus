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

void	my_print_lst(t_list *lst, char *str)
{
	t_list	*ptr;

	printf("List: %s\n", str);
	ptr = lst;
	while (ptr != NULL)
	{
		printf("%2i\n", *((int *)ptr->content));
		ptr = ptr->next;
	}
	ft_lstclear(&lst, free);
	return ;
}

int		my_load_args(int argc, char **argv, t_list **lst);
void	my_lst_sort(int argc, t_list **a, t_list **b);

int	main(int argc, char *argv[])
{
	t_list	*a;
	t_list	*b;

	a = NULL;
	b = NULL;

	my_load_args(argc, argv, &a);
	my_lst_sort(argc, &a, &b);
	return (0);
}

int	my_load_args(int argc, char **argv, t_list **lst)
{
	int		*ptr;
	t_list	*new;

	if (argc-- < 2)
		exit(0);
	ptr = NULL;
	while (argc > 0)
	{
		if (my_ascii_to_int_ptr(argv[argc], &ptr) != 0)
			my_put_err(1, *lst, NULL);
		new = ft_lstnew(ptr);
		if (new == NULL)
			my_put_err(2, *lst, ptr);
		ft_lstadd_front(lst, new);
		--argc;
	}
	if (my_has_dup(*lst))
		my_put_err(3, *lst, NULL);
	return (0);
}

void	my_lst_sort(int argc, t_list **a, t_list **b)
{
	(void)argc;
	my_rotate(a);
	my_rotate(a);
	my_reverse_rotate(a);
	my_reverse_rotate(a);
	// printf("Sorted?: %i\n", ft_lstsorted(*a, 'D'));
	my_print_lst(*a, "a");
	my_print_lst(*b, "b");
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
