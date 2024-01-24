/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstarodu <mstarodu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 22:47:14 by mstarodu          #+#    #+#             */
/*   Updated: 2024/01/24 02:13:46 by mstarodu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../get_next_line/get_next_line.h"

int	main(void)
{
	int	fd;
	char	*line;
	int	i;

	fd = open("get_new_line.txt", O_RDONLY);

	i = 1;
	line = get_next_line(fd);
	while (*line)
	{
		printf("%i - %s\n", i++, line); 	
		line = get_next_line(fd);
	}
}