/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstarodu <mstarodu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 13:36:21 by mstarodu          #+#    #+#             */
/*   Updated: 2024/01/05 21:02:56 by mstarodu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include "./libft/libft.h"
# include <stdarg.h>

int	print_c(char c);
int	print_nbr(int nbr);
int	print_str(char *s);
int	print_arg(char *c, va_list arg);
int	ft_printf(const char *s, ...);

#endif
