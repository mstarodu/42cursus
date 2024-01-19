/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstarodu <mstarodu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 13:57:02 by mstarodu          #+#    #+#             */
/*   Updated: 2024/01/19 01:15:08 by mstarodu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_str(char *s)
{
	size_t	len;
	size_t	i;
	char	*p;

	if (s)
		p = s;
	else
		p = "(null)";
	len = (int)ft_strlen(p);
	i = len;
	while (i--)
		if (print_c(*p++) == -1)
			return (-1);
	return ((int)len);
}
