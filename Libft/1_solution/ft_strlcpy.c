/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstarodu <mstarodu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 15:32:25 by mstarodu          #+#    #+#             */
/*   Updated: 2023/11/18 01:31:27 by mstarodu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	srcsize;

	srcsize = ft_strlen(src);
	if (!dstsize)
	{
		dstsize--;
		while (dstsize--)
			*dst++ = *src++;
		*dst = '\0';
	}
	return (srcsize);
}
