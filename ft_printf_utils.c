/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcousins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 18:29:19 by kcousins          #+#    #+#             */
/*   Updated: 2021/11/20 18:29:22 by kcousins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_printf.h"

int	ft_toupper(int c)
{
	if ((c >= 'a' && c <= 'z'))
	{
		c = c - 32;
		return (c);
	}
	return (c);
}

int	ft_putchar_pf(char c)
{
	int	rb;

	rb = 0;
	rb = write(1, &c, 1);
	return (rb);
}

int	ft_putstr_pf(char *s, int hex_format)
{
	int	i;

	if (!s)
	{
		write(1, "(null)", 6);
		return (6);
	}
	if (ft_strlen(s) == 0 && hex_format > 0)
		return (ft_putchar_pf('0'));
	i = 0;
	while (s[i])
	{
		if (hex_format == 2)
			s[i] = ft_toupper(s[i]);
		i += ft_putchar_pf(s[i]);
	}
	return (i);
}

int	ft_putnbr_pf(long n, int u)
{
	int	l;

	l = 0;
	if (u == 1 && n < 0)
		return (ft_putnbr_pf(4294967295 + n + 1, 0));
	if (n < 0)
	{
		l += ft_putchar_pf('-');
		n = -n;
	}
	if (n >= 10)
	{
		l += ft_putnbr_pf(n / 10, 0);
		l += ft_putchar_pf((n % 10 + '0'));
	}
	else
		l += ft_putchar_pf(n + '0');
	return (l);
}
