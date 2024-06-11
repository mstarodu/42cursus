/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstarodu <mstarodu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 21:09:47 by mstarodu          #+#    #+#             */
/*   Updated: 2024/06/11 23:17:50 by mstarodu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	my_swap(t_list *lst)
{
	void	*ptrcnt;

	if (lst == NULL || lst->next == NULL)
		return ;
	ptrcnt = lst->content;
	lst->content = lst->next->content;
	lst->content = ptrcnt;
	return ;
}

void	my_push(t_list **f, t_list **t)
{
	t_list	*ptrlst_f;
	t_list	*ptrlst_t;

	if (*f == NULL)
		return ;
	ptrlst_f = *f;
	ptrlst_t = *t;
	*f = (*f)->next;
	*t = ptrlst_f;
	(*t)->next = ptrlst_t;
	return ;
}

void	my_rotate(t_list **lst)
{
	t_list	*ptrlst;

	if (lst == NULL || (*lst)->next == NULL)
		return ;
	ptrlst = *lst;
	*lst = (*lst)->next;
	ptrlst->next = NULL;
	ft_lstadd_back(lst, ptrlst);
	return ;
}

void	my_reverse_rotate(t_list **lst)
{
	t_list	*ptrlst;
	t_list	*last;

	if (lst == NULL || (*lst)->next == NULL)
		return ;
	last = ft_lstlast(*lst);
	ptrlst = *lst;
	while (ptrlst->next != last)
		ptrlst = ptrlst->next;
	ptrlst->next = NULL;
	ft_lstadd_front(lst, last);
	return ;
}