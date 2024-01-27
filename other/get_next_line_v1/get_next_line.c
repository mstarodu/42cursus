/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstarodu <mstarodu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 01:55:26 by mstarodu          #+#    #+#             */
/*   Updated: 2024/01/26 00:51:19 by mstarodu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*parse_line(int fd, char *remainder)
{
	char	*line;
	char	*buffer;
	long long	bytes_read;
	char	*has_nextline;

	buffer = (char*)malloc(sizeof(char) * (1 + BUFFER_SIZE));
	if (!buffer)
		return (free(remainder), NULL);
	has_nextline = 0;
	while(!has_nextline)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read <= 0 && (!remainder || *remainder == '\0'))
			return(free(buffer), free(remainder), NULL);
		buffer[bytes_read] = '\0';
		line = ft_strjoin(remainder, buffer);
		if (!line)
			return (free(buffer), free(remainder), NULL);
		free(remainder);
		has_nextline = ft_strchr(line, '\n');
	}
	return (free(buffer), line);
}
char	*get_remainder(char *line)
{
	char	*newline;
	char	*remainder;

	if (!line)
		return (NULL);
	newline = ft_strchr(line, '\n');
	if (!newline)
		return (NULL);
	remainder = ft_strdup(newline + 1);
	*newline = '\0';
	return (remainder);
}

char	*get_next_line(int fd)
{
	static	char	*remainder;
	char		*line;

	line = parse_line(fd, remainder);
	remainder = get_remainder(line);

	return (line);
}
