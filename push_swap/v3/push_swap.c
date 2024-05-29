/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstarodu <mstarodu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 14:04:18 by mstarodu          #+#    #+#             */
/*   Updated: 2024/05/29 21:17:54 by mstarodu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

typedef struct		s_list
{
	void		*content;
	struct s_list	*next;
}			t_list;

t_list	*ft_lstnew(void *content)
{
	t_list	*node;

	node = (*t_list) malloc(sizeof(t_list));
	node->content = content;
	node->next = NULL;
}

int	main(int argc, char *argv[])
{
	t_list	a;
	t_list	b;
	int	args;

	args = argc - 1;
	if (args < 1)
		return (FAIL);
	if (create_stacks(&a, &b) == FAIL || collect_arguments(argv, &a) == FAIL)
		return (free_stacks(&a, &b, FAIL));
	if (check_sorted(&a) == TRUE)
		return (free_stacks(&a, &b, OK));
	// print_list(&a, "Start Stack A\n");
	// Conditions
	if (args == 2)
		sa(&a);
	else if (args == 3)
		sort_three_nodes(&a);
	else if (args <= 6) // insertion sort
	{
		while (check_sorted(&a) == FALSE)
			insertion_sort(&a, &b);
		while (b.head != NULL)
			pa(&b, &a);
	}
	else if (args < 100) // quick sort
	{}
	else if (args >= 100) // radix sort
	{}
	// printf("---\n");
	// print_list(&a, "Stack A\n");
	// print_list(&b, "Stack B\n");
	return (free_stacks(&a, &b, OK));
}
