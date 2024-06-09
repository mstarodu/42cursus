/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstarodu <mstarodu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 13:00:30 by mstarodu          #+#    #+#             */
/*   Updated: 2024/06/09 08:06:52 by mstarodu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*lstnew;
	t_list	*node;

	if (del == NULL)
		return (NULL);
	lstnew = NULL;
	while (lst != NULL)
	{
		node = ft_lstnew(lst->content);
		if (node == NULL)
		{
			ft_lstclear(&lstnew, del);
			return (NULL);
		}
		if (f != NULL)
			node = f(node->content);
		ft_lstadd_back(&lstnew, node);
		lst = lst->next;
	}
	return (lstnew);
}