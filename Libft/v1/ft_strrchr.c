/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstarodu <mstarodu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 16:54:10 by mstarodu          #+#    #+#             */
/*   Updated: 2023/12/11 22:03:14 by mstarodu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	chr;
	int		i;

	chr = (char) c;
	i = (int) ft_strlen(s);
	while (*(s + i) != chr)
	{
		if (i == 0)
			return (NULL);
		--i;
	}
	return ((char *)(s + i));
}
/*
#include <stdio.h>

int	main(void)
{
	char	*text = "Hello world! How are you?";
	int	c[] = {
		1,2,3,4,5,6,44,56,244,
		'\0', '0', 0, 134, 'w', 'y', '?', 'H'
	};

	printf("strrchr\n");
	for(size_t i = 0; i < sizeof(c)/sizeof(c[0]); i++)
	{
		printf("%p: %p --- ",
		strrchr(text, c[i]), ft_strrchr(text, c[i]));
		printf(strrchr(text, c[i]) == ft_strrchr(text, c[i])
		? "OK!\n" : "FAIL!\n");
		
	}
	return (0);
}
*/
