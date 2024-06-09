/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoip.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstarodu <mstarodu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 22:28:14 by mstarodu          #+#    #+#             */
/*   Updated: 2024/06/09 10:53:00 by mstarodu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_isspace(int c);
static char	*ft_skipandsign(char *nptr, long *sign);
static int	*ft_itop(int nbr);

int	ft_atoip(char *nptr, int **iptr)
{
	long	sign;
	char	*ptr;
	long	lnbr;

	if (nptr == NULL)
		return (1);
	sign = 1;
	ptr = ft_skipandsign(nptr, &sign);
	lnbr = 0;
	if (ft_isdigit(*ptr) == 0)
		return (2);
	while (ft_isdigit(*ptr))
	{
		lnbr = lnbr * 10 + (*ptr++ - '0');
		if (lnbr < INT_MIN || lnbr > INT_MAX)
			return (3);
	}
	*iptr = ft_itop((int)(lnbr * sign));
	if (*iptr == NULL)
		return (4);
	return (0);
}

static int	ft_isspace(int c)
{
	return (c == ' ' || c == '\f' || c == '\n'
		|| c == '\r' || c == '\t' || c == '\v');
}

static int	*ft_itop(int nbr)
{
	int	*nptr;

	nptr = (int *)malloc(sizeof(int));
	if (nptr == NULL)
		return (NULL);
	*nptr = nbr;
	return (nptr);
}

static char	*ft_skipandsign(char *nptr, long *sign)
{
	while (ft_isspace(*nptr))
		++nptr;
	if (*nptr == '+' || *nptr == '-')
	{
		if (*nptr == '-')
			*sign = -1;
		nptr++;
	}
	return (nptr);
}

// Unit Testing
/* #include <stdio.h>

int	main (void)
{
	char	*nptr;
	int *iptr;

	nptr = "   -42";
	iptr = NULL;
	printf("String: %s, Number: %ls\n", nptr, iptr);
	ft_atoip(nptr, &iptr);
	printf("String: %s, Number: %i\n", nptr, *iptr);
} */