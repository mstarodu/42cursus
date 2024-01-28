/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstarodu <mstarodu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 01:55:26 by mstarodu          #+#    #+#             */
/*   Updated: 2024/01/28 14:57:38 by mstarodu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char		*full_line;
	char		*line;
	static char	*residue;

	if (fd < 0 || BUFFER_SIZE < 0)
		return (NULL);
	full_line = read_line(fd, residue);
	line = parse('l', full_line);
	residue = parse('r', full_line);
	return (free(full_line), line);
}

char	*read_line(int fd, char *full_line)
{
	char	buffer[BUFFER_SIZE + 1];
	ssize_t	i;
	ssize_t	bytes_read;

	while (1)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read < 0)
			return (free(full_line), NULL);
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
	}
}

char	*parse(char type, char *line)
{
	size_t	i;
	size_t	llen;

	if (!line)
		return (NULL);
	llen = ft_strlen(line);
	i = 0;
	while (i < llen)
	{
		if (line[i++] == '\n')
			break ;
	}
	if (type == 'l')
		return (ft_substr(line, 0, i));
	if (type == 'r')
		return (ft_substr(line, i, llen));
	return (NULL);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	s_len;
	char	*ns;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	if (start >= s_len)
		return (NULL);
	if (len > s_len - start)
		len = s_len - start;
	ns = ft_calloc(len + 1, sizeof(*s));
	if (!ns)
		return (NULL);
	ft_strlcpy(ns, s + start, len + 1);
	return (ns);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*ns;
	size_t	s1_len;
	size_t	s2_len;

	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	ns = ft_calloc(s1_len + s2_len + 1, sizeof(*s1));
	if (!ns)
	{
		if (s1)
			free(s1);
		return (NULL);
	}
	ft_memcpy(ns, s1, s1_len);
	ft_memcpy(ns + s1_len, s2, s2_len + 1);
	if (s1)
		free(s1);
	return (ns);
}
