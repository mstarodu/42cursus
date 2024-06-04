/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstarodu <mstarodu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 14:04:18 by mstarodu          #+#    #+#             */
/*   Updated: 2024/06/04 02:36:32 by mstarodu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#include <stdio.h>

void	ft_printstck(t_list *stck)
{
	int	i;

	i = 0;
	while (stck != NULL)
	{
		printf("Index: %2i, Content: %2i, Next: %p\n",
			i++, *((int *)(stck->content)), stck->next);
		stck = stck->next;
	}
	return ;
}

int	ft_loadstck(int argc, char **argv, t_list **stck_a)
{
	int		nbr;
	int		*pnbr;
	t_list	*new;

	if (argc < 2)
		return (1);
	while (--argc > 0)
	{
		if (ft_atoi_s(argv[argc], &nbr) != 0)
		{
			ft_lstclear(stck_a, free);
			write(1, "Error\n", 6);
			return (2);
		}
		pnbr = ft_itop(nbr);
		new = ft_lstnew(pnbr);
		if (new == NULL)
		{
			ft_lstclear(stck_a, free);
			return (3);
		}
		ft_lstadd_front(stck_a, new);
	}
	return (0);
}

int	main(int argc, char *argv[])
{
	t_list	*stck_a;
	if (ft_loadstck(argc, argv, &stck_a) != 0)
		return (1);
	ft_printstck(stck_a);
	return (0);
}
