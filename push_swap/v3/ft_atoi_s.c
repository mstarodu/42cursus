/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_s.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstarodu <mstarodu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 22:28:14 by mstarodu          #+#    #+#             */
/*   Updated: 2024/06/04 01:48:21 by mstarodu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_isspace(int c)
{
	return (c == ' ' || c == '\f' || c == '\n'
		|| c == '\r' || c == '\t' || c == '\v');
}

// static long	ft_sign(char **nptr)
// {
// 	long	sign;

// 	sign = 1;
// 	if (**nptr == '+' || **nptr == '-')
// 	{
// 		if (**nptr == '-')
// 			sign = -1;
// 		(*nptr)++;
// 	}
// 	return (sign);
// }

int	ft_atoi_s(char *nptr, int *nbr)
{
	long	sign;
	long	lnbr;

	if (nptr == NULL)
		return (1);
	while (ft_isspace(*nptr))
		++nptr;
	sign = 1;
	if (*nptr == '+' || *nptr == '-')
	{
		if (*nptr == '-')
			sign = -1;
		nptr++;
	}
	lnbr = 0;
	if (ft_isdigit(*nptr) == 0)
		return (2);
	while (ft_isdigit(*nptr))
	{
		lnbr = lnbr * 10 + (*nptr++ - '0');
		if (lnbr < INT_MIN || lnbr > INT_MAX)
			return (3);
	}
	*nbr = ((int)(lnbr * sign));
	return (0);
}