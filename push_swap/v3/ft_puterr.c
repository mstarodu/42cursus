/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puterr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstarodu <mstarodu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 12:52:32 by mstarodu          #+#    #+#             */
/*   Updated: 2024/06/09 13:14:38 by mstarodu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_puterr(int err, t_list *lst, int *iptr)
{
	if (lst != NULL)
		ft_lstclear(&lst, free);
	if (iptr != NULL)
		free(iptr);
	write(STDERR_FILENO, "Error\n", 6);
	exit (err);
}
