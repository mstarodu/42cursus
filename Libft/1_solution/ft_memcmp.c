/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstarodu <mstarodu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 00:53:42 by mstarodu          #+#    #+#             */
/*   Updated: 2023/11/29 01:03:23 by mstarodu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	while (n--)
		if(*(unsigned char *)s1++ != *(unsigned char *)s2++)
			return (*(unsigned char *)(s1 - 1) - *(unsigned char *)(s2 - 1));
	return (0);
}
/*
#include <stdio.h>

int	main(void)
{
	const char *s1 = "Hello";
	const char *s2 = "Heleo";
	size_t n[] = {
		0,1,2,3,4,5,6,7,8,9,10
	};

	for(size_t i = 0; i < sizeof(n)/sizeof(n[0]); i++)
			printf("%i = %i\n",
			memcmp(s1, s2, n[i]),
			ft_memcmp(s1, s2, n[i]));
	return (0);
}
*/
