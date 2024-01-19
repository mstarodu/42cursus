/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstarodu <mstarodu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 16:58:23 by mstarodu          #+#    #+#             */
/*   Updated: 2024/01/19 00:31:24 by mstarodu         ###   ########.fr       */
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
		len = print_c(*c);
	return (len);
}

int	ft_printf(const char *s, ...)
{
	va_list	args;
	int		printflen;
	int		len;

	printflen = 0;
	va_start (args, s);
	while (*s)
	{
		if (*s == '%')
		{
			len = print_arg((char *)++s, args);
			if (len == -1)
				return (va_end(args), -1);
			printflen += len;
		}
		else
		{
			if (print_c(*s) == -1)
				return (va_end(args), -1);
			++printflen;
		}
		++s;
	}
	va_end(args);
	return (printflen);
}
