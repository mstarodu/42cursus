/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstarodu <mstarodu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 18:11:49 by mstarodu          #+#    #+#             */
/*   Updated: 2024/06/28 16:12:44 by mstarodu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <unistd.h>
# include <stdlib.h>
# define DESC '1'
# define ASC '0'
# define MAX '1'
# define MIN '0'

typedef enum e_operation
{
	sa,
	sb,
	ss,
	pa,
	pb,
	ra,
	rb,
	rr,
	rra,
	rrb,
	rrr
}			t_operation;

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

typedef struct s_move
{
	int	ra;
	int	rb;
	int	rr;
	int	rra;
	int	rrb;
	int	rrr;
	int	nbr_of_moves;		
}					t_move;

int				ft_lstsize(t_list *lst);
int				ft_isdigit(int c);
void			ft_lstadd_back(t_list **lst, t_list *new);
void			ft_lstadd_front(t_list **lst, t_list *new);
void			ft_lstclear(t_list **lst, void (*del)(void*));
void			ft_lstdelone(t_list *lst, void (*del)(void*));
void			ft_lstiter(t_list *lst, void (*f)(void *));
char			*ft_strdup(const char *s);
t_list			*ft_lstnew(void *content);
t_list			*ft_lstlast(t_list *lst);
t_list			*ft_lstmap(t_list *lst,
					void *(*f)(void *), void (*del)(void *));
size_t			ft_strlen(const char *s);
int				my_lst_find_extremum(t_list *lst, char type);
int				my_ascii_to_int_ptr(char *nptr, int **nbr);
int				my_put_err(int err, t_list *lst, int *iptr);
int				my_lst_has_dup(t_list *lst);
int				my_lst_sorted(t_list *lst, char order);
int				my_find_position(t_list *dst, int nbr, int max, int min);
void			my_swap(t_list **lst);
void			my_push(t_list **f, t_list **t);
void			my_rotate(t_list **lst);
void			my_reverse_rotate(t_list **lst);
void			my_execute(t_operation op, t_list **a, t_list **b);

#endif