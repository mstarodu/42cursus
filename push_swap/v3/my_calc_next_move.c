/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_calc_next_move.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstarodu <mstarodu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 17:53:08 by mstarodu          #+#    #+#             */
/*   Updated: 2024/06/26 22:45:17 by mstarodu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#include <stdio.h>

void	my_calc_next_move(t_list *src, t_list *dst, t_move *move)
{
	int	src_idx;
	int	position;
	int	nbr_of_moves;

	move->a_size = ft_lstsize(src);
	move->b_size = ft_lstsize(dst);
	move->a_idx = 0;
	move->b_idx = my_find_position(dst, src,
			my_lst_find_extremum(dst, MAX),
			my_lst_find_extremum(dst, MIN));
	move->nbr_of_moves = my_calc_moves(move->a_idx, move->a_size,
			move->b_idx, move->b_size);
	if (src != NULL)
		return ;
	src_idx = 0;
	while (++src_idx && src != NULL)
	{
		if (dst == NULL)
			position = 0;
		else
			position = my_find_position(dst, src,
					my_lst_find_extremum(dst, MAX),
					my_lst_find_extremum(dst, MIN));
		nbr_of_moves = my_calc_moves(src_idx, move->a_size,
				position, move->b_size);
		if (nbr_of_moves < move->nbr_of_moves)
		{
			move->a_idx = src_idx;
			move->b_idx = position;
			move->nbr_of_moves = nbr_of_moves;
		}
		src = src->next;
	}
}