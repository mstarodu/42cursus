/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstarodu <mstarodu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 22:47:24 by mstarodu          #+#    #+#             */
/*   Updated: 2024/06/04 02:31:27 by mstarodu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*todel;

	while (*lst != NULL)
	{
		ft_lstdelone(*lst, del);
		if ((*lst)->next != NULL)
		{
			todel = *lst;
			*lst = (*lst)->next;
			free (todel);
		}
	}
	*lst = NULL;
	return ;
}