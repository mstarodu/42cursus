/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_nbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstarodu <mstarodu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 13:39:17 by mstarodu          #+#    #+#             */
/*   Updated: 2024/01/18 01:10:24 by mstarodu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_nbr(long nbr, char *base)
{
	size_t	count;
	long	base_len;

	base_len = (long)ft_strlen(base);
	count = 0;
	if (nbr < 0)
	{
		ft_putchar_fd('-', 1);
		++count;
		nbr = -nbr;
	}
	if (nbr >= base_len)
		count += print_nbr(nbr / base_len, base);
	return (ft_putchar_fd(base[nbr % base_len], 1), 1 + count);
}
