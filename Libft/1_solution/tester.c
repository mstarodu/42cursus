#include <stdio.h>
#include <ctype.h>
#include "ft_isalpha.c"
#include "ft_isdigit.c"
#include "ft_isalnum.c"


int	main(void)
{
	/* ft_isalpha - ft0  */
	printf("=== ft_isalpha ===\n");
	const char test_ft0[] = {EOF, 34, 'd', 'S', -2, '-', 255, 28};
	const int number_of_ft0 = sizeof(test_ft0)/sizeof(test_ft0[0]);
	for (int i = 0; i < number_of_ft0; i++)
		printf("var: %3i | ft: %i, std: %i - %s\n",
				test_ft0[i],
				ft_isalpha(test_ft0[i]),
				isalpha(test_ft0[i]),
				(ft_isalpha(test_ft0[i]) == isalpha(test_ft0[i])) ? "OK!" : "FAIL!");

	/* ft_isdigit - ft1  */
	printf("=== ft_isdigit ===\n");
	const char test_ft1[] = {1, '1', '0', 0, EOF, -1};
	const int number_of_ft1 = sizeof(test_ft1)/sizeof(test_ft1[0]);
	for (int i = 0; i < number_of_ft1; i++)
		printf("var: %3i | ft: %i, std: %i - %s\n",
				test_ft1[i],
				ft_isdigit(test_ft1[i]),
				isdigit(test_ft1[i]),
				(ft_isdigit(test_ft1[i]) == isdigit(test_ft1[i])) ? "OK!" : "FAIL!");
	
	/* ft_isalnum - ft2  */
	printf("=== ft_isalnum ===\n");
	const char test_ft2[] = {1, '1', '0', 0, EOF, -1, EOF, 34, 'd', 'S', -2, '-', 255, 28};
	const int number_of_ft2 = sizeof(test_ft2)/sizeof(test_ft2[0]);
	for (int i = 0; i < number_of_ft2; i++)
		printf("var: %3i | ft: %i, std: %i - %s\n",
				test_ft2[i],
				ft_isalnum(test_ft2[i]),
				isalnum(test_ft2[i]),
				(ft_isalnum(test_ft2[i]) == isalnum(test_ft2[i])) ? "OK!" : "FAIL!");
	return 0;
}
