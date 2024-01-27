/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstarodu <mstarodu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 01:55:26 by mstarodu          #+#    #+#             */
/*   Updated: 2024/01/27 15:26:22 by mstarodu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*
 * 1. Input: We have a file with text
 * 2. Get buffer
 * 3. Check for \n
 * 4. Allocate remainder and buffer in full or just before \n
 * 5. Allocate remainder
 * 6. Output: line
 *
 * additinal:
 * 	protect malloc
 * 	check for NULL cases
 * 	other possible erros
*/

#include <string.h>
#include <stdio.h>

size_t	ft_strlen(const char *s)
{
	const char	*p;
	
	if (!s)
		return(0);
	p = s;
	while (*p)
		++p;
	return (p - s);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*ns;
	size_t	s1_len;
	size_t	s2_len;

	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	ns = (char *)malloc(s1_len + s2_len + 1);
	if (ns == NULL)
		return (free(s1),NULL);
	memcpy(ns, s1, s1_len);
	memcpy(ns + s1_len + 1, s2, s1_len + 1);
	return (free(s1), ns);
}

char	*get_next_line(int fd)
{
	char	buffer[BUFFER_SIZE + 1];
	ssize_t	byte_size;
	ssize_t	i;
	static char	*remainder;
	char	*line;
	int	nl;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);

	
	byte_size = read(fd, &buffer, BUFFER_SIZE);
	nl = 0;
	while (nl < 1)
	{
		if (byte_size == -1)
			return (NULL);
		buffer[byte_size] = '\0';
		i = 0;
		while(i <= byte_size)
		{
			if (buffer[i++] != '\n') 
				continue;
			buffer[i-1] = '\0';
			line  = (char *)malloc(sizeof(char) * (i - 1 + ft_strlen(remainder) + ft_strlen(pline)));
			if (!line)
				return(NULL);
			if (ft_strlen(remainder) > 0)
			{
				memcpy(line, remainder, ft_strlen(remainder));
				memcpy(&line[ft_strlen(remainder)], buffer, i - 1);	
				free(remainder);
			}
			else
				memcpy(line, buffer, i - 1);
			remainder = (char *)malloc(sizeof(char) * (byte_size - i));
			if (!remainder)
				return (NULL);
			memcpy(remainder, &buffer[i], byte_size - i);	
			return (line);
		}
		
		if (i == byte_size)
		{
			buffer[i] = '\0';
			line  = (char *)malloc(sizeof(char) * (i + ft_strlen(remainder)));
			if (!line)
				return(NULL);
			if (ft_strlen(remainder) > 0)
			{
				memcpy(line, remainder, ft_strlen(remainder));
				memcpy(&line[ft_strlen(remainder)], buffer, i);	
				free(remainder);
			}
			else
				memcpy(line, buffer, i);
			byte_size = read(fd, &buffer, BUFFER_SIZE);
		}
	}
	return (line);
}
