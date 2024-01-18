#include "../ft_printf/ft_printf.h"
#include <stdio.h>

int	main(void)
{
	char	*str = 0;
	int	d = 5;
	char	*five = "five";
	int	std = printf("STD: Hello! Hi %d(%s)! You are 100%% cool! %s - is not a number. Pointer has to point to %p\n", d, five, str, &str);
	int	ft = ft_printf(" FT: Hello! Hi %d(%s)! You are 100%% cool! %s - is not a number. Pointer has to point to %p\n", d, five, str, &str);
	printf("\n");
	printf("%d - %d", std, ft);
	printf("\n");
}
