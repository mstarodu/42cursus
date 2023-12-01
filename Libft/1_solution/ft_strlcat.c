/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstarodu <mstarodu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 00:20:06 by mstarodu          #+#    #+#             */
/*   Updated: 2023/11/28 13:03:40 by mstarodu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	srclen;
	size_t	dstlen;
	size_t	i;

	srclen = ft_strlen(src);
	dstlen = ft_strlen(dst);
	i = dstlen;
	if (dstlen >= dstsize || dstsize == 0)
		return (dstsize + srclen);
	while (i < dstsize - 1 && *src)
		dst[i++] = *src++;
	dst[i] = '\0';
	return (dstlen + srclen);
}

/*
#include <stdio.h>
int	main(void)
{
	typedef struct s_tests {
		char	test_name[50];
		
		char	*dst; 	// old text
		int	dstlen; // capacity
		
		char	*src;   // new text to add
		size_t	dstsize; // target size

	} t_test;

	t_test tests[] = {
		{"Basic", "Hello", 5, " world!", 13},
		// dstsize errors
		{"dstsize 0", "Hello", 5, " world!", 0},
		{"dstsize 1", "Hello", 5, " world!", 1},
		{"dstsize 2", "Hello", 5, " world!", 2},
		{"dstsize 15", "Hello", 5, " world!", 15},
		// string errors
		{"empty dst", "", 5, " world!", 13},
		{"empty src", "Hello", 5, "", 13},
		{"empty both", "", 5, "", 13},
		{"short src", "Hello", 5, " Sam", 13},
	};

	printf("Function: strlcat\n");
	
	for(int i = 0; i < (int)(sizeof(tests)/sizeof(tests[0])); i++)
	{
		char dst[tests[i].dstlen];
		char ft_dst[tests[i].dstlen];

		size_t dstsize = tests[i].dstsize;

		char *src = tests[i].src;
		
		strcpy(dst, tests[i].dst);
		strcpy(ft_dst, tests[i].dst);

		size_t cpysize;
		size_t ft_cpysize;

		cpysize = strlcat(dst, src, dstsize);
		ft_cpysize = ft_strlcat(ft_dst, src, dstsize);

		printf("Name: %s ", tests[i].test_name);
		
		printf("-%s- : -%s- | ", dst, ft_dst);
	
		printf("%lu : %lu | ", cpysize, ft_cpysize);

		printf((!strcmp(dst, ft_dst) && cpysize == ft_cpysize) ? "OK!" : "FAIL!");
		printf("\n");
	}
}
*/
