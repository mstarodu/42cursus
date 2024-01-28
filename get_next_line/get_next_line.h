/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstarodu <mstarodu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 01:57:51 by mstarodu          #+#    #+#             */
/*   Updated: 2024/01/28 03:46:45 by mstarodu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 100
#endif

 char    *get_next_line(int fd);
size_t  ft_strlen(const char *s);

#endif
