/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstarodu <mstarodu@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 15:24:02 by mstarodu          #+#    #+#             */
/*   Updated: 2023/12/04 22:53:52 by mstarodu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_strndup(const char *s1, size_t n)
{
	char	*d;

	d = (char *)malloc(sizeof(char) * (n + 1));
	if (d == NULL)
		return (NULL);
	ft_strlcpy(d, s1, n + 1);
	return (d);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	unsigned char	start;
	unsigned char	end;

	start = 0;
	end = ft_strlen(s1);
	while (start < end && ft_strchr(set, s1[start]))
		++start;
	while (end > start && ft_strchr(set, s1[end - 1]))
		--end;
	return (ft_strndup(s1 + start, end - start));
}
/*
#include <stdio.h>

int	main(void)
{
	printf("%s\n", ft_strtrim("dd ddd dddd", " d"));
	return (0);
}
*/
