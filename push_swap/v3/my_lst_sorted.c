/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_lst_sorted.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstarodu <mstarodu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 23:08:37 by mstarodu          #+#    #+#             */
/*   Updated: 2024/06/13 17:16:14 by mstarodu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int		my_cmp_by(int order, int a, int b);
static int		my_check_if_sorted(t_list **lst, char order, t_list *end);
static t_list	*my_find_start_point(char order, t_list *lst);

int	my_lst_sorted(t_list *lst, char order)
{
	t_list	*ptr;
	t_list	*start_point;

	if (lst == NULL || lst->next == NULL)
		return (2);
	ptr = lst;
	start_point = my_find_start_point(order, lst);
	if (start_point == ptr)
	{
		if (my_check_if_sorted(&ptr, order, NULL))
			return (2);
		return (0);
	}
	while (ptr != start_point)
		ptr = ptr->next;
	if (ptr->next != NULL)
		ptr = ptr->next;
	if (!my_check_if_sorted(&ptr, order, NULL) || !my_cmp_by(order,
			*((int *) ptr->content), *((int *) lst->content)))
		return (0);
	ptr = lst;
	if (!my_check_if_sorted(&ptr, order, start_point))
		return (0);
	return (1);
}

static int	my_cmp_by(int order, int a, int b)
{
	if ((order == ASC && a < b) || (order == DESC && a > b))
		return (1);
	return (0);
}

static t_list	*my_find_start_point(char order, t_list *lst)
{
	t_list	*start_point;

	start_point = lst;
	while (lst != NULL)
	{
		if (!my_cmp_by(order,
				*((int *) start_point->content), *((int *) lst->content)))
			start_point = lst;
		lst = lst->next;
	}
	return (start_point);
}

static int	my_check_if_sorted(t_list **lst, char order, t_list *end)
{
	t_list	*ptr;

	ptr = *lst;
	while (ptr->next != end)
	{
		if (!my_cmp_by(order,
				*((int *) ptr->content), *((int *) ptr->next->content)))
			return (0);
		ptr = ptr->next;
	}
	return (1);
}
