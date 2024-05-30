/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstarodu <mstarodu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 21:24:51 by mstarodu          #+#    #+#             */
/*   Updated: 2024/05/30 20:57:46 by mstarodu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*node;
	if (content == NULL)
		return (NULL);
	node = (t_list *) malloc(sizeof(t_list));
	if (node == NULL)
		return (NULL);
	node->content = content;
	node->next = NULL;
	return (node);
}

// // Unit Tests
// #include <stdio.h>
// int	main(void)
// {
// 	t_list	*l;
// 	int	*i;
// 	i = (int *) malloc(sizeof(i));
// 	if (i == NULL)
// 		return (1);
// 	*i = 343;
// 	l = ft_lstnew(i);
// 	if (l == NULL)
// 		return (free(i), 2);
// 	printf("Content: %i, Next: %p\n", *((int *)l->content), l->next);
// 	free(i);
// 	free(l);
// 	return (0);
// }
