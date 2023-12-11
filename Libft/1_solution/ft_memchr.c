/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstarodu <mstarodu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 22:04:09 by mstarodu          #+#    #+#             */
/*   Updated: 2023/11/29 00:19:33 by myko             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*p;
	unsigned char	chr;

	p = (unsigned char *) s;
	chr = (unsigned char) c;
	while (n--)
	{
		if (*p == chr)
			return ((void *) p);
		p++;
	}
	return (NULL);
}

/*
#include <stdio.h>
#include <string.h>

int	main(void)
{
	char	*text = "Hello world! How are you?";
	int	c[] = {
		1,2,356,244, '\0', '0', 0, 'l', 'w', 'y', '?', 'H'
	};
	size_t	n = 50;

	printf("memchr\n");
	for(size_t i = 0; i < sizeof(c)/sizeof(c[0]); i++)
	{
		printf("%s: %s --- ",
			(char*)memchr(text, c[i], n),
			(char*)ft_memchr(text, c[i], n));
		printf(memchr(text, c[i], n) == ft_memchr(text, c[i], n)
		? "OK!\n:w" : "FAIL!\n");
		
	}
	return (0);
}
*/
