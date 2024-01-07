#include "../ft_printf/ft_printf.h"
#include <stdio.h>

int	main(void)
{
	char	*str = NULL;
	int	d = 5;
	char	*five = "five";
	int	std = printf("STD: Hello! Hi %d(%s)! You are 100%% cool! %s - is not a number\n", d, five, str);
	int	ft = ft_printf(" FT: Hello! Hi %d(%s)! You are 100%% cool! %s - is not a number\n", d, five, str);
	printf("\n");
	printf("%d - %d", std, ft);
	printf("\n");
}
