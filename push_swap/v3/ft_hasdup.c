/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hasdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstarodu <mstarodu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 11:26:16 by mstarodu          #+#    #+#             */
/*   Updated: 2024/06/09 12:47:57 by mstarodu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void		*ft_iptrdup(void *iptr);
static void		ft_swap(t_list *node);
static void		ft_sortlst(t_list **stck, int lsti);
static int		ft_cmpint(t_list *stck);

static void	*ft_iptrdup(void *iptr)
{
	int	*newiptr;

	newiptr = (int *) malloc(sizeof(int));
	if (newiptr == NULL)
		return (NULL);
	*newiptr = *((int *) iptr);
	return ((void *) newiptr);
}

int	ft_hasdup(t_list *stck)
{
	t_list	*newstck;
	t_list	*pstck;
	int		lsti;

	lsti = ft_lstsize(stck) - 1;
	if (lsti == 0)
		return (0);
	newstck = ft_lstmap(stck, ft_iptrdup, free);
	if (newstck == NULL)
		return (1);
	ft_sortlst(&newstck, lsti);
	pstck = newstck;
	while (pstck->next != NULL)
	{
		if (ft_cmpint(pstck))
			return (1);
		pstck = pstck->next;
	}
	ft_lstclear(&newstck, free);
	return (0);
}

static void	ft_swap(t_list *node)
{
	void	*nptr;

	if (node->next == NULL)
		return ;
	nptr = node->content;
	node->content = node->next->content;
	node->next->content = nptr;
	return ;
}

static void	ft_sortlst(t_list **stck, int lsti)
{
	t_list	*lptr;
	int		i;

	while (lsti >= 0)
	{
		lptr = *stck;
		i = 0;
		while (i <= lsti)
		{
			if (*((int *) lptr->content) > *((int *) lptr->next->content))
				ft_swap(lptr);
			lptr = lptr->next;
			++i;
		}
		--lsti;
	}
	return ;
}

static int	ft_cmpint(t_list *stck)
{
	if (*((int *) stck->content) == *((int *) stck->next->content))
		return (1);
	return (0);
}
