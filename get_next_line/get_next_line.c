/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstarodu <mstarodu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 01:55:26 by mstarodu          #+#    #+#             */
/*   Updated: 2024/01/28 03:40:20 by mstarodu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#include <string.h>
#include <stdio.h>

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

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	char	*ns;

	if (!s || start == len )
		return (NULL);
	ns = (char *)malloc((len + 1) * sizeof(char));
	if (!ns)
		return (NULL);
	memcpy(ns, s + start, len);
	ns[len] = '\0';
	return (ns);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*ns;
	size_t	s1_len;
	size_t	s2_len;

	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	ns = (char *)malloc(s1_len + s2_len + 1);
	if (!ns)
	{
		if (s1)
			free(s1);
		return ( NULL);
	}
	memcpy(ns, s1, s1_len);
	memcpy(ns + s1_len, s2, s2_len + 1);
	if (s1)
		free(s1);
	return (ns);
}


char	*parse(char type, char *line)
{
	size_t	i;
	size_t	llen;

	if (!line)
		return (NULL);
	llen = ft_strlen(line);
	i =  0;
	while(i < llen)
	{
		if (line[i++] == '\n')
			break;
	}
	if (type == 'l')
		return (ft_substr(line, 0, i));
	if (type == 'r')
		return (ft_substr(line, i, llen));
	return (NULL);
}

char	*read_line(int fd, char *full_line)
{
	char	buffer[BUFFER_SIZE + 1];
	ssize_t	i;
	ssize_t	bytes_read;

	bytes_read = read(fd, &buffer, BUFFER_SIZE);
	while (1)
	{
		if (bytes_read < 0)
			return (free(full_line),NULL);
		if (bytes_read == 0)
			return (full_line);
		buffer[bytes_read] = '\0';
		i = 0;
		while (i < bytes_read)
		{
			if (buffer[i++] == '\n')
				return (ft_strjoin(full_line, buffer));
		}
		full_line = ft_strjoin(full_line, buffer);
		bytes_read = read(fd, buffer, BUFFER_SIZE);
	}
}

char    *get_next_line(int fd)
{
	char		*full_line;
	char		*line;
	static char	*residue;
	
	if(fd < 0 || BUFFER_SIZE < 0)
		return (NULL);
	full_line = read_line(fd, residue);
	line = parse('l', full_line);
	residue = parse('r', full_line);
	return (free(full_line), line);
}
