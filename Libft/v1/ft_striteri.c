/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstarodu <mstarodu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 18:11:39 by mstarodu          #+#    #+#             */
/*   Updated: 2023/12/13 19:08:23 by mstarodu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	i = 0;
	while (s[i])
	{
		f(i, s + i);
		++i;
	}
	return ;
}
/*
#include <stdio.h>

void	myfunc(unsigned int i, char *s)
{
	s[i] = ft_toupper(s[i]);
	return ;
}

int	main(void)
{
	char s[] = "kljkljklj hello";
	ft_striteri(s, myfunc);
	printf("%s\n", s);
}
*/
