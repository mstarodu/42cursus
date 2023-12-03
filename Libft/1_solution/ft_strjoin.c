/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstarodu <mstarodu@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 14:12:40 by mstarodu          #+#    #+#             */
/*   Updated: 2023/12/03 15:20:35 by mstarodu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ns;
	size_t	s1_len;
	size_t	s2_len;

	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	ns = (char *)malloc(s1_len + s2_len + 1);
	if (ns == NULL)
		return (NULL);
	ft_strlcpy(ns, s1, s1_len + 1);
	ft_strlcat(ns, s2, s1_len + s2_len + 1);
	return (ns);
}
