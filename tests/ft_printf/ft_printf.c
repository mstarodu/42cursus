#include "../../ft_printf/ft_printf.h"
#include <stdio.h>

int	main(void)
{
	char	*str = NULL;
	int	d = 5;
	int	dd = 55;
	char	*five = "five";
	unsigned int	ui = 3243243;
	int	std = printf("STD: Hello! Hi %%d%d(%%s%s)! You are 100%% cool! %%s%s - is not a number. Pointer has to point to %%p%p - %%u%u %%x%x %%X%X\n", d, five, str, &str, ui, dd, dd);
	int	ft = ft_printf(" FT: Hello! Hi %%d%d(%%s%s)! You are 100%% cool! %%s%s - is not a number. Pointer has to point to %%p%p - %%u%u %%x%x %%X%X\n", d, five, str, &str, ui, dd, dd);
	printf("%i  -- %i\n", std,  ft);
}
