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
	return ;
}

void	my_print_stacks(t_list *a, t_list *b)
{
	printf("_   _\n");
	while (a != NULL || b != NULL)
	{
		if (a != NULL && b != NULL)
		{
			printf("%i   %i\n", *((int *) a->content), (*((int *) b->content)));
			a = a->next;
			b = b->next;
		}
		else if (a != NULL)
		{
			printf("%i\n", *((int *) a->content));
			a = a->next;
		}
		else
		{
			printf("    %i\n", *((int *) b->content));
			b = b->next;
		}
	}
	printf("_   _\na   b\n");
}



int		my_load_args(int argc, char **argv, t_list **lst);
void	my_sort(int argc, t_list **a, t_list **b);

int	main(int argc, char *argv[])
{
	t_list	*a;
	t_list	*b;

	a = NULL;
	b = NULL;

	my_load_args(argc, argv, &a);

	my_sort(argc, &a, &b);

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

int	my_find_position(t_list *dst, int nbr, char sort)
{
	int	i;
	int	max;
	int	min;

	max = my_lst_find_extremum(dst, MAX);
	min = my_lst_find_extremum(dst, MIN);
	i = 0;
	if (dst == NULL || dst->next == NULL)
		return (i);
	if (sort == ASC)
	{
		if (nbr > max || nbr < min)
		{
			while (dst != NULL)
			{
				if (*((int *) dst->content) == max)
					return (++i);
				dst = dst->next;
				++i;
			}
		}
		else
		{
			while (dst->next != NULL)
			{
				if (*((int *) dst->content) < nbr
					&& *((int *) dst->next->content) > nbr)
					return (++i);
				dst = dst->next;
				++i;
			}
			if (dst->next == NULL)
				return (0);
		}
	}
	else
	{
		if (nbr > max || nbr < min)
		{
			while (dst != NULL)
			{
				if (*((int *) dst->content) == min)
					return (++i);
				dst = dst->next;
				++i;
			}
		}
		else
		{
			while (dst->next != NULL)
			{
				if (*((int *) dst->content) > nbr
					&& *((int *) dst->next->content) < nbr)
					return (++i);
				dst = dst->next;
				++i;
			}
			if (dst->next == NULL)
				return (0);
		}

	}
	return (i);
}

int	my_lst_find_idx(t_list *lst, int nbr)
{
	int	idx;

	idx = 0;
	while (lst != NULL && *((int *) lst->content) != nbr)
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

	extremum = my_lst_find_extremum(*lst, type);
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

void	my_init_move(t_move *move)
{
	move->ra = 0;
	move->rb = 0;
	move->rr = 0;
	move->rra = 0;
	move->rrb = 0;
	move->rrr = 0;
	move->nbr_of_moves = INT_MAX;
}

void	my_calc_moves_a(t_move *move, int i, int size, char to)
{
	if (to == B)
	{
		if (i <= size / 2)
		{
			move->ra = i;
			move->rra = 0;
		}
		else
		{
			move->ra = 0;
			move->rra = size - i;
		}
	}
	else
	{
		if (i <= size / 2)
		{
			move->rb = i;
			move->rrb = 0;
		}
		else
		{
			move->rb = 0;
			move->rrb = size - i;
		}
	}
}

void	my_calc_moves_b(t_move *move, int idx, int size, char sort, char to)
{
	if (to == B)
	{
		if (idx <= size / 2)
		{
			move->rb = idx;
			move->rrb = 0;
		}
		else
		{
			move->rb = 0;
			move->rrb = size - idx;
		}
	}
	else
	{
		if (idx <= size / 2)
		{
			move->ra = idx;
			move->rra = 0;
		}
		else
		{
			move->ra = 0;
			move->rra = size - idx;
		}
	}
}

void	my_calc_common_moves(int *one, int *two, int *common)
{
	if (*one == 0 && *two == 0)
		*common = 0;
	else if (*one > *two)
	{
		*common += *two;
		*one -= *two;
		*two = 0;
	}
	else
	{
		*common += *one;
		*two -= *one;
		*one = 0;
	}
}

void	my_calc_number_of_moves(t_move *move)
{
	my_calc_common_moves(&(move->ra), &(move->rb), &(move->rr));
	my_calc_common_moves(&(move->rra), &(move->rrb), &(move->rrr));
	move->nbr_of_moves = move->ra + move->rb + move->rr
		+ move->rra + move->rrb + move->rrr;
}

void	my_compare_moves(t_move *move, t_move *next_move)
{
	if (move->nbr_of_moves < next_move->nbr_of_moves)
	{
		next_move->ra = move->ra;
		next_move->rb = move->rb;
		next_move->rr = move->rr;
		next_move->rra = move->rra;
		next_move->rrb = move->rrb;
		next_move->rrr = move->rrr;
		next_move->nbr_of_moves = move->nbr_of_moves;
	}
}

void	my_calc_next_move(t_list **src, t_list **dst, t_move *next_move, char sort, char to)
{
	t_list	*src_ptr;
	int		src_size;
	int		dst_size;
	t_move	move;
	int		i;

	src_ptr = *src;
	src_size = ft_lstsize(*src);
	dst_size = ft_lstsize(*dst);
	i = 0;
	while (src_ptr != NULL)
	{
		my_init_move(&move);
		my_calc_moves_a(&move, i, src_size, to);
		my_calc_moves_b(&move, my_find_position(*dst,
				*((int *) src_ptr->content), sort), dst_size, sort, to);
		my_calc_number_of_moves(&move);
		my_compare_moves(&move, next_move);
		src_ptr = src_ptr->next;
		++i;
	}
}

void	my_execute_next_move(t_move *next_move, t_list **src, t_list **dst, char to)
{
	while ((next_move->ra)-- > 0)
		my_execute(ra, src, dst);
	while ((next_move->rb)-- > 0)
		my_execute(rb, src, dst);
	while ((next_move->rr)-- > 0)
		my_execute(rr, src, dst);
	while ((next_move->rra)-- > 0)
		my_execute(rra, src, dst);
	while ((next_move->rrb)-- > 0)
		my_execute(rrb, src, dst);
	while ((next_move->rrr)-- > 0)
		my_execute(rrr, src, dst);
	if (to == A)
		my_execute(pb, src, dst);
	else
		my_execute(pa, src, dst);
}

void	my_next_move (t_list **src, t_list **dst, char sort, char to)
{
	t_move	next_move;

	my_init_move(&next_move);
	my_calc_next_move(src, dst, &next_move, sort, to);
	my_execute_next_move(&next_move, src, dst, to);
}

void	my_three_sort(t_list **lst)
{
	if (*((int *)(*lst)->content)
		> *((int *)((*lst)->next->content)))
		my_execute(sa, lst, NULL);
	if (*((int *)(*lst)->content)
		> *((int *)(*lst)->next->next->content))
		my_execute(rra, lst, NULL);
	if (*((int *)(*lst)->next->content)
		> *((int *)(*lst)->next->next->content))
		my_execute(sa, lst, NULL);
	my_rotate_sort(lst, ASC);
}

void	my_six_sort(t_list **a, t_list **b)
{
	while (ft_lstsize(*a) != 3)
		my_execute(pb, a, b);
	my_three_sort(a);
	// my_print_stacks(*a, *b);
	while (*b != NULL)
		my_next_move(b, a, ASC, A);
	my_rotate_sort(a, ASC);
}

void	my_sort(int argc, t_list **a, t_list **b)
{
	int	is_sorted;
	// my_print_stacks(*a, *b);
	is_sorted = my_lst_sorted(*a, ASC);
	if (is_sorted > 0)
		my_rotate_sort(a, ASC);
	else if (argc == 3)
		my_rotate_sort(a, ASC);
	else if (argc == 4)
		my_three_sort(a);
	else if (argc < 7)
		my_six_sort(a, b);
	else
	{
		while (*a != NULL)
		{
			my_next_move(a, b, DESC, B);
			// my_print_stacks(*a, *b);
		}
		while (*b != NULL)
			my_execute(pa, a, b);
		my_rotate_sort(a, ASC);
	}
	// printf("Sorted? %i\n", my_lst_sorted(*a, ASC));
	// my_print_stacks(*a, *b);
	ft_lstclear(a, free);
	return ;
}
