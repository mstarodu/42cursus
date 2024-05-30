/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isspace.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstarodu <mstarodu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 23:56:58 by mstarodu          #+#    #+#             */
/*   Updated: 2024/05/30 00:23:12 by mstarodu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int      ft_isspace(int c)
{
        return (c == ' ' || c == '\f' || c == '\n' || c == '\r' || c == '\t' || c == '\v');
}

// Unit testing

int	main(void)
{
	char	space = ' ';
	char	form_feed = '\f';
	char	newline = '\n';
	char	carriage_return = '\r';
	char	horizontal_tab = '\t';
	char	vertical_tab = '\v';
	printf("Is space Space? 1 == %i\n", ft_isspace(space));
	printf("Is form_feed Space? 1 == %i\n", ft_isspace(form_feed));
	printf("Is newline Space? 1 == %i\n", ft_isspace(newline));
	printf("Is carriage_return Space? 1 == %i\n", ft_isspace(carriage_return));
	printf("Is horizontal_tab Space? 1 == %i\n", ft_isspace(horizontal_tab));
	printf("Is vertical_tab Space? 1 == %i\n", ft_isspace(vertical_tab));
	printf("Is 6 Space? 0 == %i\n", ft_isspace('6'));
	printf("Is N Space? 0 == %i\n", ft_isspace('N'));
}	
