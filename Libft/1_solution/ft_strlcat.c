/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstarodu <mstarodu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 00:20:06 by mstarodu          #+#    #+#             */
/*   Updated: 2023/11/27 02:01:23 by mstarodu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	return strlcat(dst, src, dstsize);
}


#include <stdio.h>

int	main(void)
{
	typedef struct s_tests {
		char	test_name[50];
		char	dst[20];
		char	src[20];
		int	dstlen;
		size_t	dstsize;

	} t_test;

	t_test tests[] = {
		{"Basic", "123456", " 7890", 11, 11},
		{"dstsize smaller", "123", " 4567890", 11, 7},
		{"dstsize is bigger", "123456", " 7890", 11, 18},
		{"dstsize is 0", "123456", " 7890", 11, 0},
		{"dstsize is super big", "123456", " 7890", 11, 38},
		{"dstlen is smaller", "123456", " 7890", 2, 11},
		{"dstlen is bigger", "123456", " 7890", 22, 11},
		{"dst is empty", "", "7890", 11, 11},
		{"src is empty", "123456", "", 11, 11},
		{"dst and src empty", "", "", 11, 11},
	};

	printf("Function: strlcat\n");
	
	for(int i = 0; i < (int)(sizeof(tests)/sizeof(tests[0])); i++)
	{
		char *src = tests[i].src;
		char *dst_text = tests[i].dst;	
		size_t dstsize = tests[i].dstsize;
		char dst[tests[i].dstlen];
		char ft_dst[tests[i].dstlen];
		
		strcpy(dst, dst_text);
		strcpy(ft_dst, dst_text);

		size_t cpysize;
		size_t ft_cpysize;
		

		cpysize = strlcat(dst, src, dstsize);
		ft_cpysize = ft_strlcat(ft_dst, src, dstsize);

		printf("Name: %s\n", tests[i].test_name);
		
		printf("%s | %lu", dst, cpysize);
	
		printf(" --- ");
		
		printf("%s | %lu ", ft_dst, ft_cpysize);

		printf((!strcmp(dst, ft_dst) && cpysize == ft_cpysize) ? "OK!" : "FAIL!");
		printf("\n\n");
	}
}
