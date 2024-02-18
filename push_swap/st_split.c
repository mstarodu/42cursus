#include <stdlib.h>

#define IN 1
#define OUT 0
#define FAIL -1
#define OK 0
#define EOS 0

typedef char * string;
typedef int result;

size_t	word_count(string s, char c)
{
	size_t	p;
	size_t	count;

	p = OUT;
	count =  0;
	while (*s != EOS)
	{
		if (*s != c && p == OUT)
		{
			p = IN;
			++count;	
		}
		else if (*s == c)
		{
			p = OUT;
		}
		++s;
	}
	return (count);
}

#include <stdio.h>

int	main(int argc, string argv[])
{
	printf("%zu\n", word_count(argv[1], ' '));
	return (0);	
}

/*
t_result st_split(const string s, char c)
{
	string	word_start;
	string	word_end;
	string	*array;
	string	word;

	if (s ==  NULL)
		return (FAIL);
	word_start = s;
	word_end = s;
	
	while (*word_end != c || *(word_end + 1) != EOS)
		word_end++;
	
}*/
	
