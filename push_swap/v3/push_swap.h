/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstarodu <mstarodu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 18:11:49 by mstarodu          #+#    #+#             */
/*   Updated: 2024/06/09 22:48:40 by mstarodu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

int				ft_lstsize(t_list *lst);
int				ft_isdigit(int c);
int				ft_atoip(char *nptr, int **nbr);
int				ft_puterr(int err, t_list *lst, int *iptr);
void			ft_lstadd_back(t_list **lst, t_list *new);
void			ft_lstadd_front(t_list **lst, t_list *new);
void			ft_lstclear(t_list **lst, void (*del)(void*));
void			ft_lstdelone(t_list *lst, void (*del)(void*));
void			ft_lstiter(t_list *lst, void (*f)(void *));
void			ft_swap(t_list *lst);
void			ft_push(t_list **f, t_list **t);
void			ft_rotate(t_list **lst);
void			ft_reverse_rotate(t_list **lst);
int				ft_hasdup(t_list *lst);
char			*strdup(const char *s);
t_list			*ft_lstnew(void *content);
t_list			*ft_lstlast(t_list *lst);
t_list			*ft_lstmap(t_list *lst, void *(*f)(void *),
					void (*del)(void *));

#endif