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

int	my_lst_find_idx(t_list *lst, int nbr)
{
	int	idx;

	idx = -1;
	while (*((int *) lst->content) != nbr)
	{
		++idx;
		lst = lst->next;
	}
	return (idx);
}

void	my_rotate_sort(t_list **lst, char type)
{
	int		extremum;
	int		position;
	int		size;
	int		side;

	extremum = my_lst_find_extremum(*lst, MIN);
	position = my_lst_find_idx(*lst, extremum);
	size = ft_lstsize(*lst);
	side = (position < (size / 2));
	while (*((int *)(*lst)->content) != extremum)
	{
		if (side)
			my_execute(ra, lst, NULL);
		else
			my_execute(rra, lst, NULL);
	}
	return ;
}

void	my_init_next_move(t_move *next_move)
{
	next_move->ra = 0;
	next_move->rb = 0;
	next_move->rr = 0;
	next_move->rra = 0;
	next_move->rrb = 0;
	next_move->rrr = 0;
	next_move->number_of_moves = INT_MAX;
}

void	my_calc_moves_a(t_move *move, int i, int a_size)
{
	if (i < a_size / 2)
	{
		move->ra = i;
		move->rra = 0;
	}
	else
	{
		move->ra = 0;
		move->rra = a_size - i;
	}
}

void	my_calc_moves_b(t_move *move, int a_idx, t_list *b, b_size)
{
	int	b_idx;

	b_idx = my_find_position(b, nbr,
			my_lst_find_extremum(b, MAX), my_lst_find_extremum(b, MIN));
	if (b_idx < b_size / 2)
	{
		move->rb = b_idx;
		move->rrb = 0;
	}
	else
	{
		move->rb = 0;
		move->rrb = b_size - b_idx;
	}
}

void	my_calc_number_of_moves(t_move *move)
{
	
}

void	my_calc_next_move(t_list **a, t_list **b, t_move *next_move)
{
	t_list	a_ptr;
	int		a_size;
	int		b_size;
	t_move	move;
	int		i;

	ptr_a = *a;
	a_size = ft_lstsize(*a);
	b_size = ft_lstsize(*b);
	i = 0;
	while (a_ptr != NULL)
	{
		my_calc_moves_a(&move, i, a_size);
		my_calc_moves_b(&move, *((int *)(a_ptr->content)), *b, b_size);
		my_calc_number_of_moves(&move);
		my_compare_moves(&move, next_moves);
		a_ptr = a_ptr->next;
	}
}

void	my_next_move (t_list **a, t_list **b)
{
	t_move	next_move;

	my_init_next_move(next_move, ft_lstsize(*a), ft_lstsize(*b));
	my_calc_next_move(a, b, &next_move);
	// execute next move
}

void	my_sort(t_list **a, t_list **b)
{
	int	is_sorted;

	is_sorted = my_lst_sorted(*a, ASC);
	if (is_sorted)
	{
		if (is_sorted == 1)
			my_rotate_sort(a, ASC);
	}
	// else
	// {
	// 	while (*a != NULL)
	// 		my_next_move(*a, *b);
	// }
	my_print_lst(*a, "a");
	my_print_lst(*b, "b");
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