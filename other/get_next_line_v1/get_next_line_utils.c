/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstarodu <mstarodu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 01:56:42 by mstarodu          #+#    #+#             */
/*   Updated: 2024/01/26 00:06:23 by mstarodu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	const char	*p;
	
	if (!s)
		return (0);
	p = s;
	while (*p)
		++p;
	return (p - s);
}

char	*ft_strchr(const char *s, int c)
{
	char	chr;

	chr = (char) c;
	while (*s != chr)
	{
		if (*s == '\0')
			return (NULL);
		++s;
	}
	return ((char *) s);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ns;
	char	*temp;
	size_t	s1_len;
	size_t	s2_len;
	
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);

	ns = (char *)malloc(s1_len + s2_len + 1);
	if (ns == NULL)
		return (NULL);
	temp = ns;
	while (s1_len--)
		*temp++ = *s1++;
	while (s2_len--)
		*temp++ = *s2++;
	*temp = '\0';
	return (ns);
}

char *ft_strdup(const char *s1)
{
    char *copy;
    size_t len;
    size_t i;

    len = 0;
    while (s1[len])
        len++;
    copy = (char *)malloc(sizeof(char) * (len + 1));
    if (!copy)
        return (NULL);
    i = 0;
    while (s1[i])
    {
        copy[i] = s1[i];
        i++;
    }
    copy[i] = '\0';
    return (copy);
}
