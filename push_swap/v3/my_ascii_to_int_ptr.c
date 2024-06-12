/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_ascii_to_int_ptr.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstarodu <mstarodu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 22:28:14 by mstarodu          #+#    #+#             */
/*   Updated: 2024/06/12 09:13:34 by mstarodu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	my_is_space(int c);
static char	*my_skip_and_sign(char *ptr, long *sign);
static int	*my_int_to_ptr(int nbr);

int	my_ascii_to_int_ptr(char *nbr_ptr, int **int_ptr)
{
	long	sign;
	char	*ptr;
	long	lnbr;

	if (nbr_ptr == NULL)
		return (1);
	sign = 1;
	ptr = my_skip_and_sign(nbr_ptr, &sign);
	lnbr = 0;
	if (ft_isdigit(*ptr) == 0)
		return (2);
	while (ft_isdigit(*ptr))
	{
		lnbr = lnbr * 10 + (*ptr++ - '0');
		if (lnbr < INT_MIN || lnbr > INT_MAX)
			return (3);
	}
	*int_ptr = my_int_to_ptr((int)(lnbr * sign));
	if (*int_ptr == NULL)
		return (4);
	return (0);
}

static int	my_is_space(int c)
{
	return (c == ' ' || c == '\f' || c == '\n'
		|| c == '\r' || c == '\t' || c == '\v');
}

static int	*my_int_to_ptr(int nbr)
{
	int	*ptr;

	ptr = (int *)malloc(sizeof(int));
	if (ptr == NULL)
		return (NULL);
	*ptr = nbr;
	return (ptr);
}

static char	*my_skip_and_sign(char *ptr, long *sign)
{
	while (my_is_space(*ptr))
		++ptr;
	if (*ptr == '+' || *ptr == '-')
	{
		if (*ptr == '-')
			*sign = -1;
		ptr++;
	}
	return (ptr);
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