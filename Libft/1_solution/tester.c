#include <stdio.h>
#include <ctype.h>
#include "libft.h"



int	main(void)
{
		printf("=\n=\n=\n   START\n=\n=\n=\n");
	{
		printf("========================================================= isalpha ===\n");
		char data[] = {'0', '\0', '*', 'A', 'a', 'Z', 'z'};
		int data_size = sizeof(data);
		
		for (int i = 0; i < data_size; i++)
			printf("var: %c, std: %i, ft: %i - %s\n", 
				data[i],
				isalpha(data[i]),
				ft_isalpha(data[i]),
				(isalpha(data[i]) == ft_isalpha(data[i])) ? "OK!" : "FAIL!" 
			);
	}
	{
		printf("========================================================= isdigit ===\n");
		char data[] = {'0', '\0', '*', 'A', 'a', 'Z', 'z', '9', '\n'};
		int data_size = sizeof(data);
		
		for (int i = 0; i < data_size; i++)
			printf("var: %c, std: %i, ft: %i - %s\n", 
				data[i],
				isdigit(data[i]),
				ft_isdigit(data[i]),
				(isdigit(data[i]) == ft_isdigit(data[i])) ? "OK!" : "FAIL!" 
			);
	}
	{
		printf("========================================================= isalnum ===\n");
		char data[] = {'0', '\0', '*', 'A', 'a', 'Z', 'z', '9', '\t'};
		int data_size = sizeof(data);
		
		for (int i = 0; i < data_size; i++)
			printf("var: %c, std: %i, ft: %i - %s\n", 
				data[i],
				isalnum(data[i]),
				ft_isalnum(data[i]),
				(isalnum(data[i]) == ft_isalnum(data[i])) ? "OK!" : "FAIL!" 
			);
	}
	{
		printf("========================================================= isascii ===\n");
		char data[] = {'0', '\0', '*', 'A', 'a', 'Z', 'z', '#', '\t', '#', '4', 'D'};
		int data_size = sizeof(data);
		
		for (int i = 0; i < data_size; i++)
			printf("var: %c, std: %i, ft: %i - %s\n", 
				data[i],
				isascii(data[i]),
				ft_isascii(data[i]),
				(isascii(data[i]) == ft_isascii(data[i])) ? "OK!" : "FAIL!" 
			);
	}
	{
		printf("========================================================= isprint ===\n");
		char data[] = {'0', '\0', '*', 'A', 'a', 'Z', 'z', '#', '\t', '#', '4', 'D'};
		int data_size = sizeof(data);
		
		for (int i = 0; i < data_size; i++)
			printf("var: %c, std: %i, ft: %i - %s\n", 
				data[i],
				isprint(data[i]),
				ft_isprint(data[i]),
				(isprint(data[i]) == ft_isprint(data[i])) ? "OK!" : "FAIL!" 
			);
	}
	{
		printf("========================================================= strlen ===\n");
		char *data[] = {"Hello", "", "World of Code"};
		int data_size = 3;
		
		for (int i = 0; i < data_size; i++)
			printf("var: %s, std: %lu, ft: %lu - %s\n", 
				data[i],
				strlen(data[i]),
				ft_strlen(data[i]),
				(strlen(data[i]) == ft_strlen(data[i])) ? "OK!" : "FAIL!" 
			);
	}
	{
		printf("========================================================= memset ===\n");
		int	size = 6;
		char	c = 'C';

		char data[] = "Hello, world";
		char ft_data[] = "Hello, world";
		
		printf("std: %s, ft: %s - %s\n", 
			(char *)memset(data, c, size),
			(char *)ft_memset(ft_data, c, size),
			!strcmp((char*)data, (char *)ft_data) ? "OK!" : "FAIL!" 
		);
	}
	{
		printf("========================================================= bzero ===\n");
		int	size = 6;

		char data[] = "Hello, world";
		char ft_data[] = "Hello, world";
		int len = (int)(sizeof(data)/sizeof(data[0]));

		bzero(data, size);
		ft_bzero(ft_data, size);

		for(int i = 0; i < len; i++)
			printf("std: %c, ft: %c - %s\n",
				data[i],
				ft_data[i],
				data[i] == ft_data[i] ? "OK!" : "FAIL!"
			);

		printf("Compare the whole string: %s\n",
			!strcmp((char*)data, (char *)ft_data) ? "OK!" : "FAIL!" 
		);
	}
	{
		printf("========================================================= memcpy ===\n");
		printf("========================================================= size 6\n");
		int	size = 6;

		char src[] = "Hello, world";
		char ft_src[] = "Hello, world";
		
		char dst[size+1];
		char ft_dst[size+1];
		
		bzero(dst, size+1);
		ft_bzero(ft_dst, size+1);

		memcpy(dst, src, size);
		ft_memcpy(ft_dst, ft_src, size);

		dst[size] = '\0';
		ft_dst[size] = '\0';

		for(int i = 0; i < size; i++)
			printf("std: %c, ft: %c - %s\n",
				dst[i],
				ft_dst[i],
				dst[i] == ft_dst[i] ? "OK!" : "FAIL!"
			);

		printf("Compare the whole string: %s\n",
			!strcmp((char*)dst, (char *)ft_dst) ? "OK!" : "FAIL!" 
		);
	}
	{
		printf("========================================================= size 0\n");
		int	size = 0;

		char *src = NULL;
		char *ft_src = NULL;
		
		char dst[size];
		char ft_dst[size];

		memcpy(dst, src, size);
		ft_memcpy(ft_dst, ft_src, size);

		for(int i = 0; i < size; i++)
			printf("std: %c, ft: %c - %s\n",
				dst[i],
				ft_dst[i],
				dst[i] == ft_dst[i] ? "OK!" : "FAIL!"
			);

		printf("Compare the whole string: %s\n",
			!strcmp((char*)dst, (char *)ft_dst) ? "OK!" : "FAIL!" 
		);
		printf("Compare the whole string: %s\n",
			!strcmp((char*)memcpy(((void *)0), ((void *)0), 3), (char *)memcpy(((void *)0), ((void *)0), 3)) ? "OK!" : "FAIL!" 
		);
	}
}
