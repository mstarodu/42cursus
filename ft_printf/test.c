#include "libftprintf.h"
#include <stdio.h>

int	main(void)
{
	int std = printf("Hello! Hi %d%%, %s\n", 5, "");
	int ft = ft_printf("Hello! Hi %d%%, %s\n", 5, "");
	printf("std: %d - ft: %d\n", std, ft);

	printf("\n");
	ft_printf("\n");
}
