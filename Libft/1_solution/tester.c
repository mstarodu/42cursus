#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "ft_isalpha.c"
#include "ft_isdigit.c"
#include "ft_isalnum.c"
#include "ft_isascii.c"
#include "ft_isprint.c"
#include "ft_strlen.c"
#include "ft_memset.c"

int	main(void)
{
	{
	printf("=== ft_isalpha ===\n");
	const char data[] = {EOF, 34, 'd', 'S', -2, '-', 255, 28};
	const int size = sizeof(data)/sizeof(data[0]);
	for (int i = 0; i < size; i++)
		printf("var: %3i | ft: %i, std: %i - %s\n",
				data[i],
				ft_isalpha(data[i]),
				isalpha(data[i]),
				(ft_isalpha(data[i]) == isalpha(data[i])) ? "OK!" : "FAIL!");
	}

	{
	printf("=== ft_isdigit ===\n");
	const char data[] = {1, '1', '0', 0, EOF, -1};
	const int number = sizeof(data)/sizeof(data[0]);
	for (int i = 0; i < number; i++)
		printf("var: %3i | ft: %i, std: %i - %s\n",
				data[i],
				ft_isdigit(data[i]),
				isdigit(data[i]),
				(ft_isdigit(data[i]) == isdigit(data[i])) ? "OK!" : "FAIL!");
	}

	{
	printf("=== ft_isalnum ===\n");
	const char data[] = {1, '1', '0', 0, EOF, -1, EOF, 34, 'd', 'S', -2, '-', 255, 28};
	const int number = sizeof(data)/sizeof(data[0]);
	for (int i = 0; i < number; i++)
		printf("var: %3i | ft: %i, std: %i - %s\n",
				data[i],
				ft_isalnum(data[i]),
				isalnum(data[i]),
				(ft_isalnum(data[i]) == isalnum(data[i])) ? "OK!" : "FAIL!");
	}

	{
	printf("=== ft_isascii ===\n");
	const char data[] = {
	    0,    // Null character
	    'a',  // Lowercase ASCII
	    'Z',  // Uppercase ASCII
	    '0',  // Digit ASCII
	    31,   // Control character (non-printable ASCII)
	    127,  // Delete (non-printable ASCII)
	    128,  // First non-ASCII character
	    255,  // Last byte value (non-ASCII)
	    -1,   // Negative value, typically represents non-ASCII
	    200   // Another non-ASCII character
	};
	const int number = sizeof(data)/sizeof(data[0]);
	for (int i = 0; i < number; i++)
		printf("var: %4i | ft: %i, std: %i - %s\n",
				data[i],
				ft_isascii(data[i]),
				isascii(data[i]),
				(ft_isascii(data[i]) == isascii(data[i])) ? "OK!" : "FAIL!");
	}
	
	{
	printf("=== ft_isprint ===\n");
	const char data[] = {
	    0,    // Null character
	    'a',  // Lowercase ASCII
	    'Z',  // Uppercase ASCII
	    '0',  // Digit ASCII
	    31,   // Control character (non-printable ASCII)
	    127,  // Delete (non-printable ASCII)
	    128,  // First non-ASCII character
	    255,  // Last byte value (non-ASCII)
	    -1,   // Negative value, typically represents non-ASCII
	    200   // Another non-ASCII character
	};
	const int number = sizeof(data)/sizeof(data[0]);
	for (int i = 0; i < number; i++)
		printf("var: %4i | ft: %i, std: %i - %s\n",
				data[i],
				ft_isprint(data[i]),
				isprint(data[i]),
				(ft_isprint(data[i]) == isprint(data[i])) ? "OK!" : "FAIL!");
	}
	
	{
	printf("=== ft_strlen ===\n");
	char *data[] = {
	"hello",
	"hi",
	"",
	"sdfds ds"
	};
	const int number = sizeof(data)/sizeof(data[0]);
	for (int i = 0; i < number; i++)
		printf("var: %10s | ft: %lu, std: %lu - %s\n",
				data[i],
				ft_strlen(data[i]),
				strlen(data[i]),
				(ft_strlen(data[i]) == strlen(data[i])) ? "OK!" : "FAIL!");
	}
	
	{
	printf("=== ft_memset ===\n");
	int n = 3;
	char ft_data[] = "hello";
	char data[] = "hello";
	ft_memset(ft_data, 'd', n);
	memset(data, 'd', n);

	for (int i = 0; i < n+1; i++)
		printf("ft: %c, std: %c\n", ft_data[i], data[i]);	
	}
	return 0;
}
