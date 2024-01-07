/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_nbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstarodu <mstarodu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 13:39:17 by mstarodu          #+#    #+#             */
/*   Updated: 2024/01/07 17:31:20 by mstarodu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_nbr(int nbr)
{
	int	i;

	i = 0;
	ft_putnbr_fd(nbr, 1);
	if (nbr < 0)
		++i;
	while (nbr > 0)
	{
		++i;
		nbr /= 10;
	}
	return (i);
}
