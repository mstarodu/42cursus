/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstarodu <mstarodu@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 12:36:02 by mstarodu          #+#    #+#             */
/*   Updated: 2023/12/03 12:54:43 by mstarodu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*d;

	d = (char *)ft_calloc(ft_strlen(s) + 1, sizeof(char));
	if (d == NULL)
		return (NULL);
	ft_strlcpy(d, s, ft_strlen(s) + 1);
	return (d);
}
