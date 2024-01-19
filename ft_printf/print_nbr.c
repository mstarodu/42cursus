/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_nbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstarodu <mstarodu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 13:39:17 by mstarodu          #+#    #+#             */
/*   Updated: 2024/01/19 01:44:04 by mstarodu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_nbr(long nbr, char *base)
{
	long	base_len;
	int		count;
	int		result;

	base_len = (long)ft_strlen(base);
	count = 0;
	if (nbr < 0)
	{
		if (print_c('-') == -1)
			return (-1);
		++count;
		nbr = -nbr;
	}
	if (nbr >= base_len)
	{
		result = print_nbr(nbr / base_len, base);
		if (result == -1)
			return (-1);
		count += result;
	}
	if (print_c(base[nbr % base_len]) == -1)
		return (-1);
	return (1 + count);
}
