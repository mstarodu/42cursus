#include <stdio.h>
#include <ctype.h>
#include "libft.h"



int	main(void)
{
	{
		printf("=== isalpha ===\n");
		char data[] = {'0', '\0', '*', 'A', 'a', 'Z', 'z'};
		int data_size = sizeof(data);
		
		for (int i = 0; i < data_size; i++)
			printf("var: %c, std: %i, ft: %i - %s\n", 
				data[i],
				isalpha(data[i]),
				ft_isalpha(data[i]),
				(isalpha(data[i]) == ft_isalpha(data[i])) ? "OK!" : "FAIL!" 
			);
		printf("\n\n\n");
	}
	{
		printf("=== isdigit ===\n");
		char data[] = {'0', '\0', '*', 'A', 'a', 'Z', 'z', '9', '\n'};
		int data_size = sizeof(data);
		
		for (int i = 0; i < data_size; i++)
			printf("var: %c, std: %i, ft: %i - %s\n", 
				data[i],
				isdigit(data[i]),
				ft_isdigit(data[i]),
				(isdigit(data[i]) == ft_isdigit(data[i])) ? "OK!" : "FAIL!" 
			);
		printf("\n\n\n");
	}
	{
		printf("=== isalnum ===\n");
		char data[] = {'0', '\0', '*', 'A', 'a', 'Z', 'z', '9', '\t'};
		int data_size = sizeof(data);
		
		for (int i = 0; i < data_size; i++)
			printf("var: %c, std: %i, ft: %i - %s\n", 
				data[i],
				isalnum(data[i]),
				ft_isalnum(data[i]),
				(isalnum(data[i]) == ft_isalnum(data[i])) ? "OK!" : "FAIL!" 
			);
		printf("\n\n\n");
	}
	{
		printf("=== isascii ===\n");
		char data[] = {'0', '\0', '*', 'A', 'a', 'Z', 'z', '#', '\t', '#', '4', 'D'};
		int data_size = sizeof(data);
		
		for (int i = 0; i < data_size; i++)
			printf("var: %c, std: %i, ft: %i - %s\n", 
				data[i],
				isascii(data[i]),
				ft_isascii(data[i]),
				(isascii(data[i]) == ft_isascii(data[i])) ? "OK!" : "FAIL!" 
			);
		printf("\n\n\n");
	}
	{
		printf("=== isprint ===\n");
		char data[] = {'0', '\0', '*', 'A', 'a', 'Z', 'z', '#', '\t', '#', '4', 'D'};
		int data_size = sizeof(data);
		
		for (int i = 0; i < data_size; i++)
			printf("var: %c, std: %i, ft: %i - %s\n", 
				data[i],
				isprint(data[i]),
				ft_isprint(data[i]),
				(isprint(data[i]) == ft_isprint(data[i])) ? "OK!" : "FAIL!" 
			);
		printf("\n\n\n");
	}
	{
		printf("=== strlen ===\n");
		char *data[] = {"Hello", "", "World of Cod"};
		int data_size = 3;
		
		for (int i = 0; i < data_size; i++)
			printf("var: %s, std: %lu, ft: %lu - %s\n", 
				data[i],
				strlen(data[i]),
				ft_strlen(data[i]),
				(strlen(data[i]) == ft_strlen(data[i])) ? "OK!" : "FAIL!" 
			);
		printf("\n\n\n");
	}
}
