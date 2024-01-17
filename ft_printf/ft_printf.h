/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstarodu <mstarodu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 13:36:21 by mstarodu          #+#    #+#             */
/*   Updated: 2024/01/12 23:02:26 by mstarodu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "./libft/libft.h"
# include <stdarg.h>

int	print_c(char c);
int	print_nbr(int nbr);
int	print_str(char *s);
int	print_arg(char *c, va_list arg);
int	print_p(unsigned long long p);
int	ft_printf(const char *s, ...);

#endif
