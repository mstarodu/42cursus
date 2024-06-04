/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstarodu <mstarodu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 14:29:32 by mstarodu          #+#    #+#             */
/*   Updated: 2024/06/01 17:42:12 by mstarodu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

// Unit tests
/* #include <stdio.h>
int	main(void)
{
	int	digit = '4';
	int	no_digit = '\n';
	printf("Digit is digit?    2 == %i\n", ft_isdigit(digit));
	printf("No digit is digit? 1 == %i\n", ft_isdigit(no_digit));
	return (1);
} */