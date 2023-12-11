/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstarodu <mstarodu@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 12:55:15 by mstarodu          #+#    #+#             */
/*   Updated: 2023/12/03 15:20:20 by mstarodu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	s_len;
	char	*ns;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	if (start >= s_len)
		return (ft_strdup(""));
	if (len > s_len - start)
		len = s_len - start;
	ns = (char *)ft_calloc(len + 1, sizeof(char));
	if (ns == NULL)
		return (NULL);
	ft_strlcpy(ns, s + start, len + 1);
	return (ns);
}
/*
#include <stdio.h>

int	main(void)
{
	char *s = "Hellodfksjfjdfjdfgfdaa";

	printf("%s\n", ft_substr(s, 2, 5));
}
*/
