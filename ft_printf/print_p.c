/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_p.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstarodu <mstarodu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 22:41:56 by mstarodu          #+#    #+#             */
/*   Updated: 2024/01/19 01:35:04 by mstarodu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	print_hex(uintptr_t p)
{
	int		count;
	char	*hex;

	hex = HEX;
	if (p == 0)
		return (0);
	else
	{
		count = print_hex(p / 16);
		if (count == -1)
			return (-1);
	}
	if (print_c(hex[p % 16]) == -1)
		return (-1);
	return (1 + count);
}

int	print_p(uintptr_t p)
{
	int	result;

	if (!p)
	{
		if (print_str("0x0") == -1)
			return (-1);
		return (3);
	}
	if (print_str("0x") == -1)
		return (-1);
	result = print_hex(p);
	if (result == -1)
		return (-1);
	return (result + 2);
}
