/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_calc_moves.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstarodu <mstarodu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 17:06:25 by mstarodu          #+#    #+#             */
/*   Updated: 2024/06/26 17:22:50 by mstarodu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	my_calc_moves(int a_idx, int a_size, int b_idx, int b_size)
{
	int	moves;

	moves = 0;
	if (a_idx < (a_size - a_idx))
		moves += a_idx;
	else
		moves += a_size - a_idx;
	if (b_idx < (b_size - b_idx))
		moves += b_idx;
	else
		moves += b_size - b_idx;
	return (moves);
}