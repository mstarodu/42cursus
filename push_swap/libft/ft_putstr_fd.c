/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstarodu <mstarodu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 18:12:24 by mstarodu          #+#    #+#             */
/*   Updated: 2023/12/13 20:34:09 by mstarodu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	size_t	slen;

	slen = ft_strlen(s);
	while (slen--)
		ft_putchar_fd(*s++, fd);
}
/*
int	main(void)
{
	ft_putstr_fd("12345", 1);
}
*/
