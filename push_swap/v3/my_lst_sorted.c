/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_lst_sorted.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstarodu <mstarodu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 23:08:37 by mstarodu          #+#    #+#             */
/*   Updated: 2024/06/13 11:41:13 by mstarodu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	my_cmp_by(int order, int a, int b)
{
	if (((order == ASC) && (a < b)) || ((order == DESC) && (a > b)))
		return (1);
	return (0);
}

int	my_lst_sorted(t_list *lst, char order)
{
	t_list	*ptr;

	if (lst == NULL || lst->next == NULL)
		return (1);
	ptr = lst;
	while (ptr->next != NULL)
	{
		if (!my_cmp_by(order,
				*((int *) ptr->content), *((int *) ptr->next->content)))
			return (0);
		ptr = ptr->next;
	}
	return (1);
}

/*
static int	my_extremum(t_list *lst, char type)
{
	int	extremum;

	extremum = *((int *) lst->content);
	while (lst != NULL)
	{
		if (!my_cmp(extremum,*((int *)lst->content), type))
			extremum = *((int *)lst->content);
		lst = lst->next;
	}
	return (extremum);
}
#include <stdio.h>

int	my_lst_sorted(t_list *lst, char type)
{
	int		first;
	t_list	*last;
	int		extremum;

	if (lst == NULL || lst->next == NULL)
		return (1);
	first = *((int *) lst->content);
	last = ft_lstlast(lst);
	extremum = my_extremum(lst, type);
	if ((*((int *) last->content) - first) )
		return (-1);
	while (lst->next != NULL)
	{
		if (*((int *)lst->content) != extremum
			&& *((int *)lst->next->content) != extremum)
		{
			if (!my_cmp(*((int *)lst->content),
					*((int *)lst->next->content), type))
				return (-1);
		}
		lst = lst->next;
	}
	return (extremum == first);
} */

/* void	my_lst_sort(t_list **a, t_list **b)
{
	
	return ;
 */
/* state int	

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

static int	my_find_start_point(t_list *lst, int type, int start_index)
{
	int	start_point;

	start_point = *((int *) lst->content);
	while (lst->next != NULL)
	{
		if (!my_compare(lst, type))
			start_point = *((int *) lst->content);
		lst = lst->next;
		++start_index;
	}
	return (start_point);
}

int	my_is_sorted(t_list *lst, int type)
{
	int			start_index;
	int			start_point;
	t_list		ptr;

	if (lst == NULL)
		return (2);
	start_index = 0;
	start_point = my_find_start_point(lst, type, &start_index);
	ptr = lst;
	while (*((int) ptr->content) != start_point)
	{
		if (!my_compare(ptr, type))
			return (0);
		ptr = ptr->next;
	}
	return (1);
} */


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
	* compare last item and the first
    * start from the begsnibg until we find max
        * return 1
    * else return 0


rotates_count(lst, cnt)
lstsize
find cnt indx 
*/
