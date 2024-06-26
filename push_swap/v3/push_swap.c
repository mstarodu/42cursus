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
void	my_sort(t_list **a, t_list **b);

int	main(int argc, char *argv[])
{
	t_list	*a;
	t_list	*b;

	a = NULL;
	b = NULL;

	my_load_args(argc, argv, &a);
	my_sort(&a, &b);

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
	if (my_lst_has_dup(*lst))
		my_put_err(3, *lst, NULL);
	return (0);
}

void	execute_next_move(t_list **a, t_list **b, t_move next_move)
{
	if (next_move->nbr_of_moves < 0)
		return ;
	else if (next_move->nbr_of_moves == 0)
		my_execute(pb, a, b);
	else
	{
		if (next_move.a_idx < (next_move.a_size - next_move.a_idx))
		{
			next_move.ra = next_move.a_idx;
			next_move.rra = 0;
		}
		else
		{
			next_move.ra = 0;
			next_move.rra = a_size - a_idx;
		}
		if (next_move.b_idx < (next_move.b_size - next_move.b_idx))
		{
			next_move.rb = next_move.b_idx;
			next_move.rrb = 0;
		}
		else
		{
			next_move.rb = 0;
			next_move.rrb = b_size - b_idx;
		}
	}
}

void	my_sort(t_list **a, t_list **b)
{
	t_move	next_move;

	my_execute(pb, a, b);
	my_execute(pb, a, b);
	my_execute(pb, a, b);
	my_calc_next_move(*a, *b, &next_move);
	
	my_print_lst(*a, "a");
	my_print_lst(*b, "b");
	printf("a_idx: %i, a_size: %i, b_idx: %i, b_size: %i, moves: %i\n",
		next_move.a_idx, next_move.a_size,
		next_move.b_idx, next_move.b_size,
		next_move.nbr_of_moves);
	return ;
}

// 

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