/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_put_err.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstarodu <mstarodu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 12:52:32 by mstarodu          #+#    #+#             */
/*   Updated: 2024/06/12 09:15:44 by mstarodu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	my_put_err(int err, t_list *lst, int *ptr)
{
	if (lst != NULL)
		ft_lstclear(&lst, free);
	if (ptr != NULL)
		free(ptr);
	write(STDERR_FILENO, "Error\n", 6);
	exit (err);
}
