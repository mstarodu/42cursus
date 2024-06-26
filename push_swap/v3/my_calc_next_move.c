/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_calc_next_move.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstarodu <mstarodu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 17:53:08 by mstarodu          #+#    #+#             */
/*   Updated: 2024/06/26 19:02:20 by mstarodu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	my_calc_next_move(t_list *src, t_list *dst, t_move *move)
{
	int	a_idx;
	int	b_idx;
	int	nbr_of_moves;

	move->a_idx = 0;
	move->a_size = ft_lstsize(src);
	move->b_idx = 0;
	move->b_size = ft_lstsize(dst);
	move->nbr_of_moves = my_calc_moves(move->a_idx, move->a_size,
			move->b_idx, move->b_size);
	if (src != NULL)
		src = src->next;
	a_idx = 1;
	while (src != NULL)
	{
		if (dst == NULL)
			b_idx = 0;
		else
			b_idx = my_find_position(dst, *((int *) src->content),
					my_lst_find_extremum(dst, MAX),
					my_lst_find_extremum(dst, MIN));
		nbr_of_moves = my_calc_moves(a_idx, move->a_size,
				b_idx, move->b_size);
		if (nbr_of_moves < move->nbr_of_moves)
		{
			move->a_idx = a_idx;
			move->b_idx = b_idx;
			move->nbr_of_moves = nbr_of_moves;
		}
		++a_idx;
		src = src->next;
	}
}