/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_p.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstarodu <mstarodu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 22:41:56 by mstarodu          #+#    #+#             */
/*   Updated: 2024/01/18 00:57:17 by mstarodu         ###   ########.fr       */
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
		count = print_hex(p / 16);
	return (ft_putchar_fd(hex[p % 16], 1), 1 + count);
}

int	print_p(uintptr_t p)
{
	char	*null;

	ft_putstr_fd("0x", 1);
	null = "0";
	if (!p)
		return (ft_putstr_fd(null, 1), 3);
	return (print_hex(p) + 2);
}
