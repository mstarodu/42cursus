/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstarodu <mstarodu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 15:54:16 by mstarodu          #+#    #+#             */
/*   Updated: 2024/06/01 17:30:08 by mstarodu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void*))
{
	if (lst == NULL || del == NULL)
		return ;
	del(lst->content);
	free(lst);
	return ;
}

// Unit tests
/* int	*ft_itop(int nbr)
{
	int	*nptr;

	nptr = (int *)malloc(sizeof(int));
	if (nptr == NULL)
		return (NULL);
	*nptr = nbr;
	return (nptr);
}

int	main(void)
{
	int		*nptr = ft_itop(55);
	t_list	*node = ft_lstnew(nptr);
	if (node == NULL)
		return (1);
	ft_lstdelone(node, free);
	return (0);
} */