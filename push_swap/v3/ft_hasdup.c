/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hasdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstarodu <mstarodu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 11:26:16 by mstarodu          #+#    #+#             */
/*   Updated: 2024/06/08 12:56:06 by mstarodu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_swap(t_list *node)
{
	void	*nptr;

	nptr = node->content;
	node->content = node->next->content;
	node->next->content = nptr;
	return ;
}

static t_list	*ft_sort(t_list **stck)
{
	t_list	*lptr;
	int		lstsize;
	int		i;

	lstsize = ft_lstsize(*stck);
	while (lstsize-- > 0)
	{
		lptr = *stck;
		i = 0;
		while (i++ < lstsize)
		{
			if (*((int *)lptr->content) > *((int *)lptr->next->content))
				ft_swap(lptr);
			lptr = lptr->next;
		}
	}
	return (*stck);
}

int	ft_hasdup(t_list **stck)
{
	t_list	*lptr;

	lptr = ft_sort(stck);
	while (lptr->next != NULL)
	{
		if (lptr->content == lptr->next->content)
			return (1);
		lptr = lptr->next;
	}
	return (0);
}
