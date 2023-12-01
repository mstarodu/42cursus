/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstarodu <mstarodu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 01:45:20 by mstarodu          #+#    #+#             */
/*   Updated: 2023/11/30 00:46:50 by mstarodu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	char	*h_end;
	char	*h;
	char	*n;

	if (!*needle)
		return ((char *) haystack);
	h_end = (char *)(haystack + len);
	while (*haystack && haystack != h_end)
	{
		h = (char *)haystack;
		n = (char *)needle;
		while (h != h_end && *h == *n && *h++ && *n++)
			;
		if (!*n)
			return ((char *) haystack);
		haystack++;
	}
	return (NULL);
}
/*
#include <string.h>
#include <stdio.h>

int	main(void)
{
	const char *largestring = "";
	const char *smallstring = "";
	char *ptr;
	char *ft_ptr;
	size_t	t = 0;
	ptr = strnstr(largestring, smallstring, t);
	ft_ptr = ft_strnstr(largestring, smallstring, t);
	
	printf(ptr == ft_ptr ? "OK!" : "FAIL!");
	printf("\n%s == %s\n", ptr, ft_ptr);

	return (0);
}
*/
