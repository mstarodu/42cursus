#include <stdio.h>
#include <ctype.h>
#include "libft.h"

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
	printf("\n\n\n");
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
	printf("\n\n\n");
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
	printf("\n\n\n");
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
	printf("\n\n\n");
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
	printf("\n\n\n");
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
	printf("\n\n\n");
	}
	
	{
	printf("=== ft_memset ===\n");
	int n = 3;
	char ft_data[] = "hello";
	char data[] = "hello";
	ft_memset(ft_data, 'd', n);
	memset(data, 'd', n);
	int data_size = (int)(sizeof(ft_data) - 1);

	for (int i = 0; i < data_size; i++)
		printf("ft: %c, std: %c - %s\n", ft_data[i], data[i], (ft_data[i] == data[i]) ? "OK!" : "FAIL!");	
	printf("\n\n\n");
	}


	{
	printf("=== ft_bzero ===\n");
	int n = 3;
	char ft_data[] = "hello";
	char data[] = "hello";
	ft_bzero(ft_data, n);
	bzero(data, n);

	int data_size = (int)(sizeof(ft_data) - 1);

	for (int i = 0; i < data_size; i++)
		printf("ft: %c, std: %c - %s\n", ft_data[i], data[i], (ft_data[i] == data[i]) ? "OK!" : "FAIL!");	
	printf("\n\n\n");
	}

	{
	printf("=== ft_memcpy ===\n");
	int n = 3;
	char ft_src[] = "hello";
	char src[] = "hello";
	char ft_dst[4];
	char dst[4];
	ft_memcpy(ft_dst, ft_src, n);
	memcpy(dst, src, n);
	int data_size = (int)(sizeof(ft_data) - 1);

	for (int i = 0; i < data_size; i++)
	for (int i = 0; i < sizeof(ft_dst) - 1; i++)
		printf("ft: %c, std: %c - %s\n", ft_dst[i], dst[i], (ft_dst[i] == dst[i]) ? "OK!" : "FAIL!");	
	printf("\n\n\n");
	}

	{
	printf("=== ft_memmove ===\n");
	printf("dest > src\n");
	int n = 10;

	char ft_origin[] = "hello world";
	char *ft_overlap = ft_origin + 2;
	
	char origin[] = "hello world";
	char *overlap = origin + 2;
	
	ft_memmove(ft_overlap, ft_origin, n);
	memmove(overlap, origin, n);
	
	int data_size = (int)(sizeof(ft_data) - 1);

	for (int i = 0; i < data_size; i++)
	for (int i = 0; i < sizeof(ft_origin) - 1; i++)
		printf("ft: %c, std: %c - %s\n", ft_origin[i], origin[i], (ft_origin[i] == origin[i]) ? "OK!" : "FAIL!");
	}


	{
   		printf("\ndest < src\n");

    		char ft_buf[20];
		bzero(ft_buf, 20);
	
		char *ft_src = ft_buf + 5;
		char *ft_dst = ft_buf;
		
		strcpy(ft_src, "Hello");
		ft_memmove(ft_dst, ft_src,7);

		char buf[20];
		bzero(buf, 20);
	
		char *src = buf + 5;
		char *dst = buf;
		
		strcpy(src, "Hello");
		memmove(dst, src,7);

	int data_size = (int)(sizeof(ft_data) - 1);

	for (int i = 0; i < data_size; i++)
    		for (int i = 0; i < sizeof(buf) - 1; i++)
		printf("ft: %c, std: %c - %s\n", ft_buf[i], buf[i], (ft_buf[i] == buf[i]) ? "OK!" : "FAIL!");
	}

	{
		int ds = 15;
		int ss = 0;

	{
		printf("=== strlcpy  ===\n");
		
		char *src = "big big ring";
		char dst[ds];
		size_t size = ss;

		printf("var: %s, std: %lu\n", dst, strlcpy(dst, src, size));
	}	
	
	{
		printf("=== ft_strlcpy  ===\n");
		
		char *src = "big big ring";
		char dst[ds];
		size_t size = ss;

		printf("var: %s, ft: %lu\n", dst, ft_strlcpy(dst, src, size));
	}
	printf("\n");
	}
	return 0;
}
