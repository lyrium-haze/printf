/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcousins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 18:28:48 by kcousins          #+#    #+#             */
/*   Updated: 2021/11/20 18:28:55 by kcousins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>

int		ft_putchar_pf(char c);
int		ft_putstr_pf(char *s, int hex_format);
int		ft_putnbr_pf(long n, int u);
int		ft_toupper(int c);
size_t	ft_strlen(const char *s);
char	*to_hex(unsigned long dec, int len, char *hex);
int		ft_printf(const char *format, ...);
#endif
