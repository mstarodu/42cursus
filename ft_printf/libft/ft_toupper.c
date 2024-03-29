/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstarodu <mstarodu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 13:07:18 by mstarodu          #+#    #+#             */
/*   Updated: 2024/01/12 23:58:47 by mstarodu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		return (c + ('A' - 'a'));
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
		printf(toupper(tests[i]) == ft_toupper(tests[i]) ? "OK! " : "FAIL! ");
	return (0);
}
*/
