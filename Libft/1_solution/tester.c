#include <stdio.h>
#include <ctype.h>
#include "ft_isalpha.c"
#include "ft_isdigit.c"
#include "ft_isalnum.c"
#include "ft_isascii.c"


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
		printf("var: %3i | ft: %i, std: %i - %s\n",
				data[i],
				ft_isascii(data[i]),
				isascii(data[i]),
				(ft_isascii(data[i]) == isascii(data[i])) ? "OK!" : "FAIL!");
	}
	return 0;
}
