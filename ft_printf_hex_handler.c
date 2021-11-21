/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hex_handler.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcousins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 18:29:06 by kcousins          #+#    #+#             */
/*   Updated: 2021/11/20 18:29:08 by kcousins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		i++;
	}
	return (i);
}

static char	*ft_strdup(const char *s1)
{
	char	*scp;
	int		i;

	scp = NULL;
	scp = (char *)malloc(ft_strlen(s1) + 1);
	if (scp == NULL)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		scp[i] = s1[i];
		i++;
	}
	scp[i] = '\0';
	return (scp);
}

static char	*ft_strdup_for_am(char **am, char *s)
{
	char	*scp;

	scp = ft_strdup(s);
	free (*am);
	return (scp);
}

char	*to_hex(unsigned long dec, int len, char *hex)
{
	int		rem;

	rem = 0;
	while (dec > 0 && len-- > 0)
	{
		rem = dec % 16;
		if (rem == 10)
			hex[len] = 'a';
		else if (rem == 11)
			hex[len] = 'b';
		else if (rem == 12)
			hex[len] = 'c';
		else if (rem == 13)
			hex[len] = 'd';
		else if (rem == 14)
			hex[len] = 'e';
		else if (rem == 15)
			hex[len] = 'f';
		else
			hex[len] = rem + '0';
		dec = dec / 16;
	}
	return (ft_strdup_for_am(&hex, hex + len));
}
