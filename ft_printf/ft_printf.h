/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstarodu <mstarodu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 13:36:21 by mstarodu          #+#    #+#             */
/*   Updated: 2024/01/18 00:24:40 by mstarodu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "./libft/libft.h"
# include <stdarg.h>
# define DEC "0123456789"
# define HEX "0123456789abcdef"
# define HEX_UPPER "0123456789ABCDEF"

int	print_c(char c);
int	print_nbr(long nbr, char *base);
int	print_str(char *s);
int	print_arg(char *c, va_list arg);
int	print_p(uintptr_t p);
int	ft_printf(const char *s, ...);

#endif
