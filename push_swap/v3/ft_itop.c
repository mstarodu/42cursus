/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itop.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstarodu <mstarodu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 00:56:20 by mstarodu          #+#    #+#             */
/*   Updated: 2024/06/04 00:59:18 by mstarodu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*ft_itop(int nbr)
{
	int	*nptr;

	nptr = (int *)malloc(sizeof(int));
	if (nptr == NULL)
		return (NULL);
	*nptr = nbr;
	return (nptr);
}