/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstarodu <mstarodu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 14:09:40 by mstarodu          #+#    #+#             */
/*   Updated: 2024/06/08 12:15:51 by mstarodu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_lstsize(t_list *lst)
{
	long	size;

	size = 0;
	if (lst == NULL)
		return (size);
	while (lst->next != NULL)
	{
		lst = lst->next;
		++size;
	}
	return (size);
}
