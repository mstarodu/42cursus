/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_find_position.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstarodu <mstarodu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 22:08:01 by mstarodu          #+#    #+#             */
/*   Updated: 2024/06/26 13:10:04 by mstarodu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	my_find_position(t_list *lst, int nbr, int max, int min)
{
	int	i;

	i = 0;
	if (lst == NULL || lst->next == NULL || max == min)
		;
	else if (nbr > max || nbr < min)
	{
		while (*((int *) lst->content) != max && ++i)
			lst = lst->next;
	}
	else
	{
		while (++i && !(*((int *) lst->content) > nbr
				&& *((int *) lst->next->content) < nbr))
		{
			lst = lst->next;
			if (lst->next == NULL)
				return (0);
		}
	}
	return (i);
}