/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstarodu <mstarodu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 12:07:21 by mstarodu          #+#    #+#             */
/*   Updated: 2024/06/01 17:11:05 by mstarodu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

int				ft_atoi(const char *nptr);
int				ft_lstsize(t_list *lst);
int				ft_isdigit(int c);
void			ft_lstadd_back(t_list **lst, t_list *new);
char			*strdup(const char *s);
t_list			*ft_lstnew(void *content);
t_list			*ft_lstlast(t_list *lst);

#endif