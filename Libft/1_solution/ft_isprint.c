/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstarodu <mstarodu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 01:50:24 by mstarodu          #+#    #+#             */
/*   Updated: 2023/11/16 01:57:01 by mstarodu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isprint(int c)
{
	unsigned char	uc;

	uc = (unsigned char)c;
	if (uc >= 32 && uc <= 126)
		return (1);
	return (0);
}
