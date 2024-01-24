/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstarodu <mstarodu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 01:55:26 by mstarodu          #+#    #+#             */
/*   Updated: 2024/01/24 02:38:47 by mstarodu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft/libft.h"
/*
int	has_no_newline(t_list *list)
{
	if(list == NULL)
		return (0)
	while (list->next_line != NULL)
		list = list->next_line;
	while(list->buffer != '\n')

}

t_list	parse(int fd) 
{
	t_list	*list;
	while (has_no_newline)
	{
	
	}

	return (list);
}
*/

char	*get_next_line(int fd)
{
	static char	*remainder;
	char	buffer[BUFFER_SIZE + 1];
	ssize_t	bytes_read;
	char	*line;
	char	*old_line;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	bytes_read = read(fd, buffer, BUFFER_SIZE);
	if (remainder)
		line = ft_strdup(remainder);
	else
	{
	line = malloc(sizeof(char));
	*line = '\0';
	}
	while (bytes_read > 0)
	{
		buffer[bytes_read] = '\0';
		old_line = line;
		remainder = ft_strchr(buffer, '\n');		
		if (remainder)
		{
			remainder = (*remainder = '\0', ft_strdup(remainder + 1));
			line = ft_strjoin(line, buffer);	
			break;
		}
		line = ft_strjoin(line, buffer);	
		free(old_line);
		bytes_read = read(fd, buffer, BUFFER_SIZE);
	}
	return (line);
}
