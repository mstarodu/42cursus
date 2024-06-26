/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_find_position.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstarodu <mstarodu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 22:08:01 by mstarodu          #+#    #+#             */
/*   Updated: 2024/06/26 11:15:06 by mstarodu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	my_lst_find_extremum(t_list *lst, char type)
{
	int	nbr;

	nbr = *((int *) lst->content);
	while (*lst != NULL)
	{
		if (type == MAX)
		{
			if (nbr < *((int *) lst->next->content))
				nbr = *((int *) lst->content);
		}
		else
		{
			if (nbr < *((int *) lst->next->content))
				nbr = *((int *) lst->content);
		}
		lst = *lst->next;
	}
	return (nbr);
}

static int	my_is_new_extremum(t_list *lst, int nbr)
{
	int min;
	int max;
	int	i;

	min = my_lst_find_extremum(lst, MIN);
	max = my_lst_find_extremum(lst, MAX);
	i = 0;
	if (nbr < min || nbr > max)
		return (1);
	return (0);
}

int	my_find_position(t_list *lst, int nbr, int min, int max)
{
	int	i;

	i = 0;
	if (lst == NULL)
		return (i);
	// if NBR is an EXTREMUM
	if (my_is_new_extremum(lst, nbr))
	{
		// then between MAX and MIN
	}
	// else beetween bigger && smaller number. If smaller is the first element, then 0



	j{
		while (!(*((int *) lst->content) > nbr
				&& *((int *) lst->next->content) < nbr)
			|| NULL != *((int *) lst->next->content))
			++i;
		if (*((int *) lst->next->content) == NULL)
			return (0);
		++i;
	}
	return (i);
}

// #### find_position
// is X lower then minimum? if yes -> new min and place AFTER current min
// is X higher then maximum? if yes -> new max and place BEFORE current max
// otherwise, put between y > X > y+1