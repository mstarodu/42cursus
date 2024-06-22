/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_find_position.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstarodu <mstarodu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 22:08:01 by mstarodu          #+#    #+#             */
/*   Updated: 2024/06/22 23:06:31 by mstarodu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	my_lst_min_and_max(t_list *lst, int *min, int *max)
{
	if (lst == NULL)
		return (-1);
	while (lst != NULL)
	{
		if (*((int *) lst->content) < *min)
			min = *((int *) lst->content);
		if (*((int *) lst->content) > *max)
			max = *((int *) lst->content);
		lst = lst->next;
	}
	return (0);
}

int	my_find_position(t_list *lst, int nbr, int min, int max)
{
	int	size;
	int	i;

	if (lst == NULL)
		return (-1);
	size = ft_lstsize(lst);
	i = 0;
	if (my_lst_min_and_max(lst, &min, &max) < 0)
		return (0);
	if (nbr < min || nbr > max)
	{
		while (*((int *) lst->content) != min)
			++i;
		if (i == size - 1)
			return (0);
		else
			++i;
	}
	else
	{
		while (!(*((int *) lst->content) > nbr
				&& *((int *) lst->next->content) < nbr))
			++i;
		++i; /// case with number at edges
	}
	return (i);
}

// #### find_position
// is X lower then minimum? if yes -> new min and place AFTER current min
// is X higher then maximum? if yes -> new max and place BEFORE current max
// otherwise, put between y > X > y+1