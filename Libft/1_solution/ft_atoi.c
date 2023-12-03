/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstarodu <mstarodu@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 15:29:51 by mstarodu          #+#    #+#             */
/*   Updated: 2023/12/01 17:03:00 by mstarodu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isspace(char c)
{
	if (c == ' ' || c == '\f' || c == '\n'
		|| c == '\r' || c == '\t' || c == '\v')
		return (1);
	return (0);
}

int	ft_atoi(const char *nptr)
{
	int	sign;
	int	nbr;

	sign = 1;
	nbr = 0;
	while (ft_isspace(*nptr))
		nptr++;
	if (*nptr == '-' || *nptr == '+')
	{
		if (*nptr == '-')
			sign = -1;
		nptr++;
	}
	while (ft_isdigit(*nptr))
		nbr = nbr * 10 + (*nptr++ - '0');
	return (nbr * sign);
}
/*
#include <stdio.h>
#include <limits.h>
int	main(void)
{
	char	*tests[] = {
		"0", "0123", "f", "+1", "-0", "---+0",
		"+---+3324", "", "   ", "  454 454 45", "212-"
	};

	for(int i = 0; i < 11; i++)
	{
		if (atoi(tests[i]) != ft_atoi(tests[i]))
			printf("%s >\nst: >%d<\nft: >%d<\n\n",
			tests[i], atoi(tests[i]), ft_atoi(tests[i]));
	}
	
	printf("Done\n");


	return (0);
}
*/
