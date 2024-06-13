/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_has_dup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstarodu <mstarodu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 11:26:16 by mstarodu          #+#    #+#             */
/*   Updated: 2024/06/12 18:15:13 by mstarodu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void		*my_int_ptr_dup(void *iptr);
static void		my_lst_sort(t_list **lst, int lstindx);
static int		my_int_cmp(t_list *lst);

int	my_has_dup(t_list *lst)
{
	t_list	*new_lst;
	t_list	*ptr_lst;
	int		indx;

	indx = ft_lstsize(lst) - 1;
	if (indx == 0)
		return (0);
	new_lst = ft_lstmap(lst, my_int_ptr_dup, free);
	if (new_lst == NULL)
		return (1);
	my_lst_sort(&new_lst, indx);
	ptr_lst = new_lst;
	while (ptr_lst->next != NULL)
	{
		if (my_int_cmp(ptr_lst))
			return (1);
		ptr_lst = ptr_lst->next;
	}
	ft_lstclear(&new_lst, free);
	return (0);
}

static void	*my_int_ptr_dup(void *iptr)
{
	int	*newiptr;

	newiptr = (int *) malloc(sizeof(int));
	if (newiptr == NULL)
		return (NULL);
	*newiptr = *((int *) iptr);
	return ((void *) newiptr);
}

static void	my_lst_sort(t_list **lst, int indx)
{
	t_list	*ptr;
	int		i;

	while (indx >= 0)
	{
		ptr = *lst;
		i = 0;
		while (i <= indx)
		{
			if (*((int *) ptr->content) > *((int *) ptr->next->content))
				my_swap(ptr);
			ptr = ptr->next;
			++i;
		}
		--indx;
	}
	return ;
}

static int	my_int_cmp(t_list *lst)
{
	if (*((int *) lst->content) == *((int *) lst->next->content))
		return (1);
	return (0);
}
