/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstarodu <mstarodu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 13:00:30 by mstarodu          #+#    #+#             */
/*   Updated: 2024/06/09 12:44:15 by mstarodu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*newlst;
	void	*newcnt;
	t_list	*newnd;

	if (lst == NULL || f == NULL || del == NULL)
		return (NULL);
	newlst = NULL;
	while (lst != NULL)
	{
		newcnt = f(lst->content);
		if (newcnt == NULL)
			return (NULL);
		newnd = ft_lstnew(newcnt);
		if (newnd == NULL)
		{
			free(newcnt);
			ft_lstclear(&newlst, del);
			return (NULL);
		}
		ft_lstadd_back(&newlst, newnd);
		lst = lst->next;
	}
	return (newlst);
}
