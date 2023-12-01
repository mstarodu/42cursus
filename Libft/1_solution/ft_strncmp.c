/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstarodu <mstarodu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 17:52:30 by mstarodu          #+#    #+#             */
/*   Updated: 2023/11/28 19:14:08 by mstarodu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	while (*s1 == *s2 && *s1 && *s2 && n)
	{
		++s1;
		++s2;
		--n;
	}
	if(n == 0)
		return (0);
	return ((unsigned char)*s1 - (unsigned char)*s2);
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
			printf("%i = %i\n", strncmp(s1, s2, n[i]), ft_strncmp(s1, s2, n[i]));
	return (0);
}
*/
