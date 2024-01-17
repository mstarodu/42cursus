/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_p.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstarodu <mstarodu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 22:41:56 by mstarodu          #+#    #+#             */
/*   Updated: 2024/01/13 00:55:48 by mstarodu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*convert_p_to_hex_str(unsigned long long p)
{
	p -= p;
	return ("dddD");
}

int	print_p(unsigned long long p)
{
	int	len;
	char	*str;

	str = convert_p_to_hex_str(p);
	ft_putstr_fd(str, 1);
	len = ft_strlen(str);
	return (len);
}
