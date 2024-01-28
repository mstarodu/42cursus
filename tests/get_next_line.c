/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstarodu <mstarodu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 22:47:14 by mstarodu          #+#    #+#             */
/*   Updated: 2024/01/28 16:45:36 by mstarodu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../get_next_line/get_next_line.h"

int	main(int argc, char *argv[])
{
	int	fd;
	char	*line;
	int	i;
	
	if (argc > 1)
	{
		fd = open(argv[1], O_RDONLY);
		if (!fd)
			return (printf("Error opening file\n"), 1);
		i = 1;
		line = get_next_line(fd);
		while (line)
		{
			printf("%i - %s\n", i++, line); 	
			free(line);
			line = get_next_line(fd);
		}
		close(fd);
	}
	else
	{
        	while ((line = get_next_line(0)) != NULL)
		{
            		printf("%s", line);
            		free(line);
        	}
	}
    return (0);
}
