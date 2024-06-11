/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_puterr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstarodu <mstarodu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 12:52:32 by mstarodu          #+#    #+#             */
/*   Updated: 2024/06/11 23:17:46 by mstarodu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	my_puterr(int err, t_list *lst, int *iptr)
{
	if (lst != NULL)
		ft_lstclear(&lst, free);
	if (iptr != NULL)
		free(iptr);
	write(STDERR_FILENO, "Error\n", 6);
	exit (err);
}
