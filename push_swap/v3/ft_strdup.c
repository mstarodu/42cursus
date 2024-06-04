/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstarodu <mstarodu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 16:09:53 by mstarodu          #+#    #+#             */
/*   Updated: 2024/06/04 00:33:26 by mstarodu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*ft_strdup(const char *s)
{
	char	*space;
	char	*ptr;
	size_t	len_of_s;
	char	*new_s;

	ptr = (char *) s;
	len_of_s = 0;
	while (*ptr != '\0')
	{
		++len_of_s;
		++ptr;
	}
	space = (char *) malloc(sizeof(char) * (len_of_s + 1));
	if (space == NULL)
		return (NULL);
	ptr = (char *) s;
	new_s = space;
	while (*ptr != '\0')
		*space++ = *ptr++;
	*space = '\0';
	return (new_s);
}

// Unit test
/* #include <stdio.h>
#include <string.h>
int main(void)
{
	printf("Text: %s\n", ft_strdup("dsd"));
	printf("Text: %s\n", strdup("dsd"));
	return (0);
} */