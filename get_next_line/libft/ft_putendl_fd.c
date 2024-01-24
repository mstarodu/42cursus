/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstarodu <mstarodu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 18:13:01 by mstarodu          #+#    #+#             */
/*   Updated: 2023/12/13 20:37:32 by mstarodu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	size_t	slen;

	slen = ft_strlen(s);
	while (slen--)
		ft_putchar_fd(*s++, fd);
	ft_putchar_fd('\n', fd);
}
/*
int	main(void)
{
	ft_putendl_fd("12345", 1);
}
*/
