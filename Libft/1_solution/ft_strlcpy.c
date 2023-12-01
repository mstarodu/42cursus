/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstarodu <mstarodu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 15:32:25 by mstarodu          #+#    #+#             */
/*   Updated: 2023/11/28 01:34:31 by mstarodu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	srcsize;

	srcsize = ft_strlen(src);
	if (dstsize != 0)
	{
		if (dstsize - 1 >= srcsize)
			ft_memmove(dst, src, srcsize + 1);
		else
		{
			ft_memmove(dst, src, dstsize - 1);
			*(dst + dstsize - 1) = '\0';
		}
	}
	return (srcsize);
}

/*
#include <stdio.h>

int	main(void)
{
	typedef	struct s_tests {
		int	dst_len;
		size_t	dstsize;
		char	*src;
	} t_test;

	t_test test[] = {
		{20, 6, "Hello"},
		{20, 13, "Hello, how"},
		{20, 1222, "Hello darling how are you?"},
		{20, 20, "Hello"},
		{2, 5, "Helloooooo"},
		{20, 5, ""},
		{20, 0, "Hello"},
		{0, 5, "Hello"},
		{0, 0, "Hello"},
	};

	for (int i = 0; i < (int)(sizeof(test) / sizeof(test[0])); i++)
	{
		char dest[test[i].dst_len];
		//bzero(dest, test[i].dst_len);
		char ft_dest[test[i].dst_len];
		//bzero(ft_dest, test[i].dst_len);
		char *src = test[i].src;
		size_t	dstsize = test[i].dstsize;;
		size_t	std;
		size_t	ft;

		std = strlcpy(dest, src, dstsize);
		ft = ft_strlcpy(ft_dest, src, dstsize);
		printf("%lu : %lu | %s : %s - ", std, ft, dest, ft_dest);
		printf( std == ft && !strcmp(dest, ft_dest) ? "Ok!" : "FAIL!");
		printf("\n");

	}	

	return (0);
}
*/
