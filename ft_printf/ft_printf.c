/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstarodu <mstarodu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 16:58:23 by mstarodu          #+#    #+#             */
/*   Updated: 2024/01/18 01:13:36 by mstarodu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_arg(char *c, va_list arg)
{
	int	len;

	if (*c == 'c')
		len = print_c(va_arg(arg, int));
	else if (*c == 'd' || *c == 'i' )
		len = print_nbr((long)va_arg(arg, int), DEC);
	else if (*c == 'u')
		len = print_nbr((long)va_arg(arg, unsigned int), DEC);
	else if (*c == 's')
		len = print_str(va_arg(arg, char *));
	else if (*c == 'p')
		len = print_p(va_arg(arg, uintptr_t));
	else if (*c == 'x')
		len = print_nbr((long)va_arg(arg, unsigned int), HEX);
	else if (*c == 'X')
		len = print_nbr((long)va_arg(arg, unsigned int), HEX_UPPER);
	else
		len = (ft_putchar_fd(*c, 1), 1);
	return (len);
}

int	ft_printf(const char *s, ...)
{
	va_list	args;
	int		printflen;

	printflen = 0;
	va_start (args, s);
	while (*s)
	{
		if (*s == '%')
			printflen += print_arg((char *)++s, args);
		else
			printflen += (ft_putchar_fd(*s, 1), 1);
		++s;
	}
	va_end(args);
	return (printflen);
}
