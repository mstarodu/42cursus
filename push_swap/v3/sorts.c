/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorts.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstarodu <mstarodu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 23:08:37 by mstarodu          #+#    #+#             */
/*   Updated: 2024/06/09 23:54:26 by mstarodu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_lstsorted(t_list *lst, char order)
{
	int	i;
	int j;

	if (lst == NULL || (order != 'A' && order != 'D'))
		return (-1);
	if (lst->next == NULL)
		return (0);
	i = 0;
	j = *((int *) lst->content);
	while (lst->next != NULL)
	{
		if (order == 'D')
		{
			if (*((int *) lst->content) < *((int *) lst->next->content))
			{
				if (*((int *) lst->next->content) > j)
					return (-1);
				++i;
			}
		}
		else
		{
			if (*((int *) lst->content) > *((int *) lst->next->content))
			{
				if (*((int *) lst->next->content) < j)
					return (-1);
				++i;
			}
		}
		lst = lst->next;
	}
	return (i);
}