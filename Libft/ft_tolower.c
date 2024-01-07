/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstarodu <mstarodu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 13:23:21 by mstarodu          #+#    #+#             */
/*   Updated: 2023/12/22 11:57:38 by mstarodu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		return (c - ('A' - 'a'));
	return (c);
}
/*
#include <stdio.h>
#include <ctype.h>
int	main(void)
{
	char	tests[] = {
		'a', 'A', ' ', '\0', '	', 'e', 'Z', 'z'
	};
	for (size_t i = 0; i < sizeof(tests)/sizeof(tests[0]); i++)
		printf(tolower(tests[i]) == ft_tolower(tests[i]) ? "OK! " : "FAIL! ");
	return (0);
}
*/
