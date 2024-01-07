/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstarodu <mstarodu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 22:57:14 by mstarodu          #+#    #+#             */
/*   Updated: 2023/12/15 13:04:11 by mstarodu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_words(const char *s, char c)
{
	size_t	words;
	char	in_word;

	words = 0;
	in_word = 0;
	while (*s)
	{
		if (*s != c && in_word == 0)
		{
			++words;
			in_word = 1;
		}
		else if (*s == c)
			in_word = 0;
		++s;
	}
	return (words);
}

static void	*free_arr(char **arr, size_t arr_size)
{
	size_t	i;

	i = 0;
	while (i < arr_size)
		free(arr[i++]);
	free(arr);
	return (NULL);
}

static char	**allocate_words(const char *s, char c, size_t words, char **arr)
{
	const char	*word_start;
	const char	*word_end;
	size_t		i;

	i = 0;
	while (i < words)
	{
		while (*s == c)
			s++;
		word_start = s;
		while (*s && *s != c)
			s++;
		word_end = s;
		arr[i] = ft_substr(word_start, 0, word_end - word_start);
		if (!arr[i++])
			return (free_arr(arr, i));
	}
	arr[i] = NULL;
	return (arr);
}

char	**ft_split(char const *s, char c)
{
	size_t	words;
	char	**arr;

	words = count_words(s, c);
	arr = (char **) malloc((words + 1) * sizeof(char *));
	if (!arr)
		return (NULL);
	return (allocate_words(s, c, words, arr));
}
/*
#include <stdio.h>
int	main (void)
{
	char *str = "helloi who are u   ";
	char del = ' ';
	size_t size = count_words(str, del);
	char	**n = ft_split(str, del);

	for (size_t i = 0; i <= size; i++)
		printf("%s\n", n[i] == NULL ? "NULL" : n[i]);	
	return (0);
}
*/
