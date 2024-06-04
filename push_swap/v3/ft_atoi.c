/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstarodu <mstarodu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 21:47:19 by mstarodu          #+#    #+#             */
/*   Updated: 2024/06/04 00:32:11 by mstarodu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_isspace(int c)
{
	return (c == ' ' || c == '\f' || c == '\n'
		|| c == '\r' || c == '\t' || c == '\v');
}

int	ft_atoi(const char *nptr)
{
	long	sign;
	long	r;

	if (nptr == (void *) 0)
		return (0);
	while (ft_isspace(*nptr))
		++nptr;
	sign = 1;
	if (*nptr == '+' || *nptr == '-')
	{
		if (*nptr == '-')
			sign = -1;
		++nptr;
	}
	r = 0;
	while (ft_isdigit(*nptr))
	{
		r = r * 10 + (*nptr++ - '0');
		if (r < INT_MIN || r > INT_MAX)
			return (0);
	}
	r *= sign;
	return ((int) r);
}

// Unit Tests
/* #include	<stdio.h>
#include	<stdlib.h>
int	main(int argc, char *argv[])
{
	if (argc > 1)
		printf("atoi: %i; ft_atoi: %i\n", atoi(argv[1]), ft_atoi(argv[1]));
	printf("INT_MIN | atoi: %i; ft_atoi: %i\n",
		atoi("INT_MIN"), ft_atoi("INT_MIN"));
	printf("INT_MAX | atoi: %i; ft_atoi: %i\n",
		atoi("INT_MAX"), ft_atoi("INT_MAX"));
	printf("LONG_MAX | atoi: %i; ft_atoi: %i\n",
		atoi("+9223372036854775807"),
		ft_atoi("LONG_MAX"));
	printf("-42 | atoi: %i; ft_atoi: %i\n", atoi("-42"), ft_atoi("-42"));
} */