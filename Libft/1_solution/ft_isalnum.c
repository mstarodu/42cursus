/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstarodu <mstarodu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 00:46:21 by mstarodu          #+#    #+#             */
/*   Updated: 2023/11/16 01:08:06 by mstarodu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	s_ft_isalpha(int c)
{
	unsigned char	uc;

	uc = (unsigned char)c;
	if ((uc >= 'A' && uc <= 'Z') || (uc >= 'a' && uc <= 'z'))
		return (1);
	return (0);
}

static int	s_ft_isdigit(int c)
{
	unsigned char	uc;

	uc = (unsigned char)c;
	if (uc >= '0' && uc <= '9')
		return (1);
	return (0);
}

int	ft_isalnum(int c)
{
	return (s_ft_isalpha(c) || s_ft_isdigit(c));
}
