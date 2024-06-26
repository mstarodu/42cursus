/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_lst_find_extremum.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstarodu <mstarodu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 11:25:00 by mstarodu          #+#    #+#             */
/*   Updated: 2024/06/26 12:48:12 by mstarodu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	my_lst_find_extremum(t_list *lst, char type)
{
	int	nbr;

	nbr = *((int *) lst->content);
	while (lst != NULL)
	{
		if (type == MAX)
		{
			if (nbr < *((int *) lst->content))
				nbr = *((int *) lst->content);
		}
		else
		{
			if (nbr > *((int *) lst->content))
				nbr = *((int *) lst->content);
		}
		lst = lst->next;
	}
	return (nbr);
}