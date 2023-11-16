/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstarodu <mstarodu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 00:34:29 by mstarodu          #+#    #+#             */
/*   Updated: 2023/11/16 00:40:46 by mstarodu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isdigit(int c)
{
	unsigned char	uc;

	uc = (unsigned char)c;
	if (uc >= '0' && uc <= '9')
		return (1);
	return (0);
}
