/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstarodu <mstarodu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 16:13:49 by mstarodu          #+#    #+#             */
/*   Updated: 2023/12/13 18:10:53 by mstarodu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*d;
	unsigned int	i;

	if (!s || !f)
		return (NULL);
	d = (char *)ft_calloc((ft_strlen(s) + 1), sizeof(char));
	if (!d)
		return (NULL);
	i = 0;
	while (s[i])
	{
		d[i] = f(i, s[i]);
		i++;
	}
	return (d);
}
/*
#include <stdio.h>

char	my_func(unsigned int s, char c)
{
	s++;
	s--;
	return (ft_toupper(c));
}

int	main()
{
	printf("%s\n", ft_strmapi("hello world!", my_func));	
}*/
