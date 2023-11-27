/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstarodu <mstarodu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 15:32:25 by mstarodu          #+#    #+#             */
/*   Updated: 2023/11/27 00:25:19 by mstarodu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	//return (strlcpy(dst,src, dstsize));
	size_t	srcsize;
	size_t r;

	srcsize = ft_strlen(src);

	if (!dstsize)
		return (srcsize);

	r = srcsize;	 
	while (srcsize-- && --dstsize)
		*dst++ = *src++;
	*dst = '\0';
	return (r);
}
/*
#define ARRSIZE 10
#include <stdio.h>
int	main(void)
{
	{
		printf("BASIC: ");
		char dst[10];
		size_t dstsize = sizeof(dst) / sizeof(*dst);
		size_t cpysize;
		char *src = "Hello";
		bzero(dst, ARRSIZE);

		cpysize = strlcpy(dst, src, dstsize);
		printf("%s | %lu", dst, cpysize);

		printf(" --- ");
		bzero(dst, ARRSIZE);

		cpysize = ft_strlcpy(dst, src, dstsize);
		printf("%s | %lu\n", dst, cpysize);
	}
	{
		printf("dstsize 0: ");
		char dst[10];
		size_t dstsize = 0;
		size_t cpysize;
		char *src = "Hello";
		bzero(dst, ARRSIZE);

		cpysize = strlcpy(dst, src, dstsize);
		printf("%s | %lu", dst, cpysize);

		printf(" --- ");
		bzero(dst, ARRSIZE);

		cpysize = ft_strlcpy(dst, src, dstsize);
		printf("%s | %lu\n", dst, cpysize);
	}
	{
		printf("dstsize < srcsize: ");
		char dst[10];
		size_t dstsize = 3;
		size_t cpysize;
		char *src = "Hello";
		bzero(dst, ARRSIZE);

		cpysize = strlcpy(dst, src, dstsize);
		printf("%s | %lu", dst, cpysize);

		printf(" --- ");
		bzero(dst, ARRSIZE);

		cpysize = ft_strlcpy(dst, src, dstsize);
		printf("%s | %lu\n", dst, cpysize);
	}
	{
		printf("dstsize == srcsize - No place for NULL terminator: ");
		char dst[10];
		size_t dstsize = sizeof(dst) / sizeof(*dst);
		size_t cpysize;
		char *src = "Hello67890";
		bzero(dst, ARRSIZE);

		cpysize = strlcpy(dst, src, dstsize);
		printf("%s | %lu", dst, cpysize);

		printf(" --- ");
		bzero(dst, ARRSIZE);

		cpysize = ft_strlcpy(dst, src, dstsize);
		printf("%s | %lu\n", dst, cpysize);
	}
	{
		printf("dstsize == srcsize (inc null): ");
		char dst[10];
		size_t dstsize = sizeof(dst) / sizeof(*dst);
		size_t cpysize;
		char *src = "Hello6789";
		bzero(dst, ARRSIZE);

		cpysize = strlcpy(dst, src, dstsize);
		printf("%s | %lu", dst, cpysize);

		printf(" --- ");
		bzero(dst, ARRSIZE);

		cpysize = ft_strlcpy(dst, src, dstsize);
		printf("%s | %lu\n", dst, cpysize);
	}
	{
		printf("dstsize < srcsize: ");
		char dst[10];
		size_t dstsize = sizeof(dst) / sizeof(*dst);
		size_t cpysize;
		char *src = "Hello678901234";
		bzero(dst, ARRSIZE);

		cpysize = strlcpy(dst, src, dstsize);
		printf("%s | %lu", dst, cpysize);

		printf(" --- ");
		bzero(dst, ARRSIZE);

		cpysize = ft_strlcpy(dst, src, dstsize);
		printf("%s | %lu\n", dst, cpysize);
	}
}*/
