/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstarodu <mstarodu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 23:16:36 by mstarodu          #+#    #+#             */
/*   Updated: 2024/03/02 15:20:15 by mstarodu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# define PLUS 1
# define MINUS -1
# define OK 0
# define FAIL -1
# define TRUE 1
# define FALSE 0
# define TOP 0
# define BOTTOM 1

typedef char*	t_string;
typedef struct s_node
{
	int				nbr;
	struct s_node	*next;
}	t_node;
typedef struct s_list
{
	t_node	*head;
	t_node	*tail;
}	t_list;

#endif
