/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstarodu <mstarodu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 21:24:51 by mstarodu          #+#    #+#             */
/*   Updated: 2024/06/01 16:54:36 by mstarodu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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

// Unit Tests
/* #include <stdio.h>
int	main(void)
{
    int *i = (int *) malloc(sizeof(int));
    if (i == NULL)
        return (1);
    *i = 343;
    t_list *l = ft_lstnew(i);
    if (l == NULL)
    {
        free(i);
        return (2);
    }
    printf("Content: %d, Next: %p\n", *((int *)l->content), (void *)l->next);
    free(i);
    free(l);
    return (0);
} */