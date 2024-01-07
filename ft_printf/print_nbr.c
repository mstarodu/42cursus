/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_nbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstarodu <mstarodu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 13:39:17 by mstarodu          #+#    #+#             */
/*   Updated: 2024/01/07 19:13:28 by mstarodu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_nbr(int nbr)
{
	char	*s_nbr;
	int		len;

	s_nbr = ft_itoa(nbr);
	len = ft_strlen(s_nbr);
	return (ft_putstr_fd(s_nbr, 1), free(s_nbr), len);
}
