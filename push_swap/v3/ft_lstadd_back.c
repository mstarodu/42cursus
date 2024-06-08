/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstarodu <mstarodu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 12:00:39 by mstarodu          #+#    #+#             */
/*   Updated: 2024/06/08 16:54:14 by mstarodu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*node;

	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	node = ft_lstlast(*lst);
	node->next = new;
	return ;
}

// Unit tests
/* #include <stdio.h>

void	ft_printstck(t_list *stck)
{
	int	i = 0;
	while (stck != NULL)
	{
		printf("Index: %2i, Content: %2i, Next: %p\n",
			i++, *((int *)(stck->content)), stck->next);
		stck = stck->next;
	}
	return ;
}

int	main(void)
{
	int		*content1;
	int		*content2;
	int		*content3;
	t_list	*stck;
	t_list	*new;

	content1 = (int *) malloc(sizeof(int));
	if (content1 == NULL)
		return (1);
	*content1 = 55;
	
	content2 = (int *) malloc(sizeof(int));
	if (content2 == NULL)
		return (free(content1), 2);
	*content2 = 22;
	
	content3 = (int *) malloc(sizeof(int));
	if (content3 == NULL)
		return (free(content1), free(content2), 3);
	*content3 = 12;

	stck = ft_lstnew(content1);
	new = ft_lstnew(content2);
	
	ft_lstadd_back(&stck, new);
	
	new = ft_lstnew(content3);
	ft_lstadd_back(&stck, new);
	
	ft_printstck(stck);
	return (0);
} */