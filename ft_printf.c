/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcousins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 18:28:36 by kcousins          #+#    #+#             */
/*   Updated: 2021/11/20 18:28:40 by kcousins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	digit_nbr(unsigned long n)
{
	int	i;
	int	res;

	i = 0;
	res = 0;
	while (n != 0)
	{
		n = n / 10;
		res++;
	}
	return (res);
}

static int	p_handler(va_list args_ptr)
{
	void	*ptr;
	char	*adr;
	int		len;

	ptr = va_arg(args_ptr, void *);
	len = digit_nbr((uintptr_t)ptr);
	adr = NULL;
	adr = (char *)malloc(len + 1);
	adr[len] = '\0';
	adr = to_hex((uintptr_t)ptr, len, adr);
	len = 0;
	len += ft_putstr_pf("0x", 0);
	len += ft_putstr_pf(adr, 1);
	free(adr);
	return (len);
}

static int	x_handler(va_list args_ptr, char format)
{
	char			*hex;
	unsigned int	dec;
	int				len;

	dec = va_arg(args_ptr, int);
	len = digit_nbr(dec);
	hex = NULL;
	hex = (char *)malloc(len + 1);
	hex[len] = '\0';
	hex = to_hex(dec, len, hex);
	len = 0;
	if (format == 'x')
		len += ft_putstr_pf(hex, 1);
	else
		len += ft_putstr_pf(hex, 2);
	free(hex);
	return (len);
}

static	int	format_handler(va_list args_ptr, char format)
{
	int	len;

	len = 0;
	if (format == 'c')
		len += ft_putchar_pf(va_arg(args_ptr, int));
	else if (format == 's')
		len += ft_putstr_pf(va_arg(args_ptr, char *), 0);
	else if (format == 'p')
		len += p_handler(args_ptr);
	else if (format == 'd' || format == 'i')
		len += ft_putnbr_pf(va_arg(args_ptr, int), 0);
	else if (format == 'u')
		len += ft_putnbr_pf(va_arg(args_ptr, int), 1);
	else if (format == 'x' || format == 'X')
		len += x_handler(args_ptr, format);
	else if (format == '%')
		len += ft_putchar_pf('%');
	return (len);
}

int	ft_printf(const char *format, ...)
{
	va_list	args_ptr;
	int		i;
	int		res_len;

	i = 0;
	res_len = 0;
	va_start(args_ptr, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			res_len += format_handler(args_ptr, format[i]);
		}
		else
			res_len += ft_putchar_pf(format[i]);
		i++;
	}
	return (res_len);
}
