#include "../ft_lstnew.c"
#include <assert.h>


int	main(void)
{
	int	*n;
	t_list	*list;

	n = malloc(sizeof(int));
	*n = 55; 
	list = ft_lstnew(n);
	assert(*n == *(int *)list->content);
	assert(NULL == list->next);
	return (0);
}
