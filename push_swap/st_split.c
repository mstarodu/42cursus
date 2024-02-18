#include "push_swap.h"

size_t	word_count(t_string s, char c, size_t *wc)
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

t_result	st_malloc(size_t nmemb, size_t size, t_string **dst)
{
	*dst = (t_string *)malloc(nmemb * size);
	if (*dst == NULL)
		return (FAIL);
	return (OK);
}
	
void	free_arr(t_string **arr, size_t wc)
{
	size_t	i;

	i = 0;
	while (i < wc)
		free((*arr)[i++]);
	free(*arr);	
}

t_result	create_word(t_string start, t_string end, t_string **dst, size_t word)
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

t_result	collect_words(t_string s, char c, size_t wc, t_string **arr)
{
	size_t	p;
	t_string	word_start;
	size_t	word;

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
			if(create_word(word_start, s, arr, word++) == FAIL)
				return(free_arr(arr, wc), FAIL);
		}
		++s;
	}
	(*arr)[word] = NULL;
	return (OK);
}

t_string	*st_split(t_string s, char c)
{
	t_string	*arr;
	size_t			wc;

	arr = NULL;
	if (s ==  NULL
		|| word_count(s, c, &wc) == 0
		|| st_malloc(wc + 1, sizeof(char*), &arr) == FAIL
		|| collect_words(s, c, wc, &arr) == FAIL)
		return (NULL);
	return (arr);	
}
	
#include <stdio.h>

int	main(void)
{
	size_t	i;
	size_t	wc;
	t_string *words;
	t_string argv = "  Hello,   world! i  ";

	wc = 0;
	word_count(argv, ' ', &wc);

	printf("%zu\n", wc);
	words = st_split(argv, ' ');
	i = 0;
	while (i < wc)
		printf("%s\n", words[i++]);
	printf("%s\n", words[i]);
	free_arr(&words, wc);
	return (0);	
}
