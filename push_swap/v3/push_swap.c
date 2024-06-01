/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstarodu <mstarodu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 14:04:18 by mstarodu          #+#    #+#             */
/*   Updated: 2024/06/01 18:11:30 by mstarodu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#include <stdio.h>

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

int	ft_loadstcks(int c, char **argv, t_list **stck_a)
{
	
}

int	main(int argc, char *argv[])
{
	t_list	*stck_a;

	if (argc < 2)
		return (1);
	if (ft_loadstck() == 0)
	{
		write(1, "Error\n", 6)
		return (0);
	}

	return (0);
}
