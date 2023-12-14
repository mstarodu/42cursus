/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstarodu <mstarodu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 13:27:24 by mstarodu          #+#    #+#             */
/*   Updated: 2023/12/11 21:58:25 by mstarodu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	chr;

	chr = (char) c;
	while (*s != chr)
	{
		if (*s == '\0')
			return (NULL);
		++s;
	}
	return ((char *) s);
}
/*
#include <stdio.h>

int	main(void)
{
	char	*text = "Hello world! How are you?";
	int	c[] = {
		1,2,3,4,5,6,44,56,244, '\0', '0', 0, 134, 'a', '!'
	};

	printf("strchr\n");
	for(size_t i = 0; i < sizeof(c)/sizeof(c[0]); i++)
	{
		printf("%p: %p --- ", 
			strchr(text, c[i]),
			ft_strchr(text, c[i]));
		printf(strchr(text, c[i]) == ft_strchr(text, c[i])
		? "OK!\n" : "FAIL!\n ");
	}
	return (0);
}
*/
