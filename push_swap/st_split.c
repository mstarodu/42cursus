#include <stdlib.h>

#define IN 1
#define OUT 0
#define FAIL -1
#define OK 0
#define EOS 0

typedef char * t_string;
typedef int t_result;

size_t	word_wc(t_string s, char c, size_t *wc)
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
		else if (*s == c)
		{
			p = OUT;
		}
		++s;
	}
	return (*wc);
}

t_result	st_calloc(size_t nmemb, size_t size, t_string **dst)
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
		free(arr[i++]);
	free(arr);	
}

t_result	create_word(t_string start, t_string end, t_string **dst)
{
	size_t	i;

	*dst = malloc((end - start + 1) * sizeof(char));
	if (dst == NULL)       
		return (FAIL);
	i = 0;
	while (&start != &end)
		(*dst)[i++] = *start++;
	(*dst)[i] = '\0';
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
		else if (*s == c || *s == '\0')
		{
			p = OUT;
			if(create_word(word_start, s, (*arr)[word]) == FAIL)
				return(free_arr(*arr, wc), FAIL);
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
		|| word_wc(s, c, &wc) == 0
		|| st_calloc(wc + 1, sizeof(char*), &arr) == FAIL
		|| collect_words(s, c, wc, &arr) == FAIL)
		return (NULL);
	return (arr);	
}
	
#include <stdio.h>

int	main(int argc, t_string argv[])
{
	size_t	i;
	size_t	wc;
	t_string *words;

	if (argc < 2)
		return(printf("No arguments. Try next time\n"), 0);
	wc = 0;
	word_wc(argv[1], ' ', &wc);

	printf("%zu\n", wc);
	words = st_split(argv[1], ' ');
	i = 0;
	while (i < wc)
		printf("%s\n", words[i++]);
	printf("%p\n", words[i]);
	return (0);	
}
