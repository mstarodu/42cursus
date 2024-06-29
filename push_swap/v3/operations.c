/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstarodu <mstarodu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 21:09:47 by mstarodu          #+#    #+#             */
/*   Updated: 2024/06/29 20:30:12 by mstarodu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	my_swap(t_list **lst)
{
	void	*ptr;

	if (*lst == NULL || (*lst)->next == NULL)
		return ;

	ptr = (*lst)->content;
	(*lst)->content = (*lst)->next->content;
	(*lst)->next->content = ptr;
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

void	my_execute(t_operation op, t_list **a, t_list **b)
{
	const char	*str_op[] = {"sa", "sb", "ss", "pa", "pb",
		"ra", "rb", "rr", "rra", "rrb", "rrr"};

	if (op == sa || op == ss)
		my_swap(a);
	if (op == sb || op == ss)
		my_swap(b);
	if (op == pa)
		my_push(b, a);
	if (op == pb)
		my_push(a, b);
	if (op == ra || op == rr)
		my_rotate(a);
	if (op == rb || op == rr)
		my_rotate(b);
	if (op == rra || op == rrr)
		my_reverse_rotate(a);
	if (op == rrb || op == rrr)
		my_reverse_rotate(b);
	write(STDOUT_FILENO, str_op[op], ft_strlen(str_op[op]));
	write(STDOUT_FILENO, "\n", 1);
}
