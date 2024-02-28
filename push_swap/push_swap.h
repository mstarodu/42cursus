/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstarodu <mstarodu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 23:16:36 by mstarodu          #+#    #+#             */
/*   Updated: 2024/02/28 21:23:10 by mstarodu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# define DUMMY 0
# define PLUS 1
# define MINUS -1
# define OK 0
# define FAIL -1
# define TRUE 1
# define FALSE 0
# define EOS 0
# define IN 1
# define OUT 0

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
