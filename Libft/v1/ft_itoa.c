/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstarodu <mstarodu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 22:44:33 by mstarodu          #+#    #+#             */
/*   Updated: 2023/12/15 13:02:39 by mstarodu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	nbrlen(long int ln)
{
	int	nlen;

	if (ln < 0)
	{
		ln *= -1;
		nlen = 2;
	}
	else
		nlen = 1;
	while (ln > 9)
	{
		ln /= 10;
		++nlen;
	}
	return (nlen);
}

static char	*nstr(char *d, int nlen, long int ln)
{
	int	edge;

	edge = 0;
	if (ln < 0)
	{
		ln *= -1;
		d[0] = '-';
		++edge;
	}
	while (--nlen >= edge)
	{
		d[nlen] = ln % 10 + '0';
		ln /= 10;
	}
	return (d);
}

char	*ft_itoa(int n)
{
	long int		ln;
	int				nlen;
	char			*d;

	ln = (long int) n;
	nlen = nbrlen(ln);
	d = (char *) ft_calloc(nlen + 1, sizeof(char));
	if (!d)
		return (NULL);
	return (nstr(d, nlen, ln));
}
/*
#include <stdio.h>
int	main(void)
{
	int nbr = -3242332;
	printf("%s\n", ft_itoa(nbr));
}
*/
