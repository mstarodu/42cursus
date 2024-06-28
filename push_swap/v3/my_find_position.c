/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_find_position.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstarodu <mstarodu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 22:08:01 by mstarodu          #+#    #+#             */
/*   Updated: 2024/06/28 15:30:58 by mstarodu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	my_find_position(t_list *dst, int nbr, int max, int min)
{
	int	i;

	i = 0;
	if (src == NULL)
		return (-1);
	if (dst == NULL || dst->next == NULL || max == min)
		;
	else if (nbr > max || nbr < min)
	{
		while (*((int *) dst->content) != max && ++i)
			dst = dst->next;
	}
	else
	{
		while (++i && !(*((int *) dst->content) > nbr
				&& *((int *) dst->next->content) < nbr))
		{
			dst = dst->next;
			if (dst->next == NULL)
				return (0);
		}
	}
	return (i);
}