/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hasdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstarodu <mstarodu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 11:26:16 by mstarodu          #+#    #+#             */
/*   Updated: 2024/06/09 21:19:45 by mstarodu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void		*ft_iptrdup(void *iptr);
static void		ft_lstsort(t_list **lst, int lstindx);
static int		ft_intcmp(t_list *lst);

int	ft_hasdup(t_list *lst)
{
	t_list	*newlst;
	t_list	*ptrlst;
	int		lstindx;

	lstindx = ft_lstsize(lst) - 1;
	if (lstindx == 0)
		return (0);
	newlst = ft_lstmap(lst, ft_iptrdup, free);
	if (newlst == NULL)
		return (1);
	ft_lstsort(&newlst, lstindx);
	ptrlst = newlst;
	while (ptrlst->next != NULL)
	{
		if (ft_intcmp(ptrlst))
			return (1);
		ptrlst = ptrlst->next;
	}
	ft_lstclear(&newlst, free);
	return (0);
}

static void	*ft_iptrdup(void *iptr)
{
	int	*newiptr;

	newiptr = (int *) malloc(sizeof(int));
	if (newiptr == NULL)
		return (NULL);
	*newiptr = *((int *) iptr);
	return ((void *) newiptr);
}

static void	ft_lstsort(t_list **lst, int lstindx)
{
	t_list	*lptr;
	int		i;

	while (lstindx >= 0)
	{
		lptr = *lst;
		i = 0;
		while (i <= lstindx)
		{
			if (*((int *) lptr->content) > *((int *) lptr->next->content))
				ft_swap(lptr);
			lptr = lptr->next;
			++i;
		}
		--lstindx;
	}
	return ;
}

static int	ft_intcmp(t_list *lst)
{
	if (*((int *) lst->content) == *((int *) lst->next->content))
		return (1);
	return (0);
}
