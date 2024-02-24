/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   st_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstarodu <mstarodu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 00:07:20 by mstarodu          #+#    #+#             */
/*   Updated: 2024/02/24 23:52:06 by mstarodu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_result	count_words(t_string s, char c, size_t *wc, t_string **dst)
{
	size_t	p;

	p = OUT;
	while (*s != EOS)
	{
		if (*s != c && p == OUT)
		{
			p = IN;
			++(*wc);
		}
		else if (*s == c && p == IN)
		{
			p = OUT;
		}
		++s;
	}
	if (*wc == 0)
		return (FAIL);
	*dst = (t_string *) malloc((*wc + 1) * sizeof(t_string));
	if (*dst == NULL)
		return (FAIL);
	return (OK);
}

static void	free_arr(t_string **arr, size_t wc)
{
	size_t	i;

	i = 0;
	while (i < wc)
		free((*arr)[i++]);
	free(*arr);
}

static t_result	create_word(t_string start, t_string end,
		t_string **dst, size_t word)
{
	size_t	i;
	size_t	edge;

	(*dst)[word] = (t_string) malloc((end - start + 1) * sizeof(char));
	if ((*dst)[word] == NULL)
		return (FAIL);
	i = 0;
	edge = end - start;
	while (i <= edge)
	{
		(*dst)[word][i] = start[i];
		++i;
	}
	(*dst)[word][i] = '\0';
	return (OK);
}

static t_result	collect_words(t_string s, char c, size_t wc, t_string **arr)
{
	size_t		p;
	t_string	word_start;
	size_t		word;

	p = OUT;
	word = 0;
	while (*s != EOS)
	{
		if (*s != c && p == OUT)
		{
			p = IN;
			word_start = s;
		}
		else if ((*(s + 1) == c || *(s + 1) == EOS) && p == IN)
		{
			p = OUT;
			if (create_word(word_start, s, arr, word++) == FAIL)
				return (free_arr(arr, wc), FAIL);
		}
		++s;
	}
	(*arr)[word] = NULL;
	return (OK);
}

t_result	st_split(t_string s, char c, t_string **arr)
{
	size_t		wc;

	wc = 0;
	if (s == NULL
		|| count_words(s, c, &wc, arr) == FAIL
		|| collect_words(s, c, wc, arr) == FAIL)
		return (FAIL);
	return (OK);
}
/*
#include <stdio.h>

int	main(void)
{
	t_string	*arr;
	int	i;

	arr = NULL;
	i = 0;
	st_split("one two three", ' ', &arr);
	while (i < 3)
		printf("%s\n", arr[i++]);
}
*/
/*
#include <stdio.h>

size_t	word_c(t_string s, char c, size_t *wc)
{
	size_t	p;

	p = OUT;
	while (*s != EOS)
	{
		if (*s != c && p == OUT)
		{
			p = IN;
			++(*wc);
		}
		else if (*s == c && p == IN)
		{
			p = OUT;
		}
		++s;
	}
	return (*wc);
}
int	main(void)
{
	size_t	i;
	size_t	wc;
	t_string *words;
	t_string argv = " sdcs sdisd ics dssd sd ds  Hello,   world! i  ";

	wc = 0;
	word_c(argv, ' ', &wc);

	printf("%zu\n", wc);
	words = st_split(argv, ' ');
	i = 0;
	while (i < wc)
		printf("%s\n", words[i++]);
	printf("%s\n", words[i]);
	free_arr(&words, wc);
	return (0);	
}
*/
