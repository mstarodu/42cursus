/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstarodu <mstarodu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 22:47:24 by mstarodu          #+#    #+#             */
/*   Updated: 2024/06/09 21:37:13 by mstarodu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*lptr;
	t_list	*todel;

	if (*lst == NULL)
		return ;
	lptr = *lst;
	*lst = NULL;
	while (lptr->next != NULL)
	{
		todel = lptr;
		lptr = lptr->next;
		ft_lstdelone(todel, del);
	}
	ft_lstdelone(lptr, del);
	return ;
}
