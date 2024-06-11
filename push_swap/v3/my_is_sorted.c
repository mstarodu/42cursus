/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_is_sorted.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstarodu <mstarodu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 23:08:37 by mstarodu          #+#    #+#             */
/*   Updated: 2024/06/12 00:24:30 by mstarodu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

state int	

static int	my_compare(t_list *lst, int type)
{
	int	result;

	if (type == 0)
		if (*((int *) lst->content) <= *((int *) lst->next->content))
			result = 1;
	else if (type == 1)
		if (*((int *) lst->content) >= *((int *) lst->next->content))
			result = 1;
	else
		result = 0;
	return (result);
}

static int	my_find_start_point(t_list *lst, char type)
{
	int	start_point;
	
	start_point = 
	while (lst->next != NULL)
	{

	}
}

int	my_is_sorted(t_list *lst, int type)
{
	int		start_point;
	t_list	ptr;

	if (lst == NULL)
		return (2);
	start_point = my_find_start_point(lst, type);
	ptr = lst;
	while (*((int) ptr->content) != start_point)
		ptr = ptr->next;
	while (ptr->next != NULL)
	{
		if (!my_compare(ptr, type))
			return (0);
		ptr = ptr->next;
	}
	ptr = lst;
	while (*((int) ptr->content) != start_point)
	{
		if (!my_compare(ptr, type))
			return (0);
		ptr = ptr->next;
	}
	return (1);
}


/*
lstsorted(lst, order)
- Desc. 
    * lstsize
    * Find max abd its index
    * Move to max
    * Start comp until the end
    * if max index == 0
        * return 2
    * if max index != 0
    * start from the beginibg until we find max
        * return 1
    * else return 0


rotates_count(lst, cnt)
lstsize
find cnt indx 
*/
