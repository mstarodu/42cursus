/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstarodu <mstarodu@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 18:36:57 by mstarodu          #+#    #+#             */
/*   Updated: 2023/12/11 21:53:38 by mstarodu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*p;

	if (nmemb && size > SIZE_MAX / nmemb)
		return (NULL);
	p = malloc(nmemb * size);
	if (p == NULL)
		return (NULL);
	ft_bzero(p, nmemb * size);
	return (p);
}
/*
#include <stdio.h>
int main() {
    size_t nmemb = SIZE_MAX / 2 + 1;
    size_t size = 2;

    void *ptr_std = calloc(nmemb, size);
    void *ptr_ft = ft_calloc(nmemb, size);

    if (ptr_std == NULL)
        printf("calloc returned NULL\n");
    else
        printf("calloc returned allocated memory\n");

    if (ptr_ft== NULL)
        printf("ft_calloc returned NULL\n");
    else
        printf("ft_calloc returned allocated memory\n");

    free(ptr_std);
    free(ptr_ft);

    return 0;
}
*/
