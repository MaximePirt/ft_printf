/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpierrot <mpierrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 11:15:51 by maxime_pier       #+#    #+#             */
/*   Updated: 2024/01/18 21:24:14 by mpierrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static size_t	numlen(int n)
{
	size_t	b;

	b = 0;
	if (n == -2147483648)
		return (11);
	if (!n)
		return (1);
	if (n < 0)
	{
		b++;
		n *= -1;
	}
	while (n > 0)
	{
		n /= 10;
		b++;
	}
	return (b);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strdup(const char *src)
{
	char	*c;
	int		i;
	int		len;

	i = 0;
	len = ft_strlen(src);
	c = malloc(sizeof(char) * len + 1);
	if (c == NULL)
		return (NULL);
	while (src[i] != '\0')
	{
		c[i] = src[i];
		i++;
	}
	c[i] = '\0';
	return (c);
}

static char	*fillitoa(int n, size_t len, int negative, char *res)
{
	while (n > 0)
	{
		res[len-- + negative - 1] = (n % 10) + '0';
		n /= 10;
	}
	return (res);
}

char	*ft_itoa(int n)
{
	size_t	len;
	int		negative;
	char	*res;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	len = numlen(n);
	res = (char *)malloc(sizeof(char) * (len + 1));
	if (!res)
		return (NULL);
	negative = (n < 0);
	if (n < 0)
	{
		res[0] = '-';
		n *= -1;
		len--;
	}
	if (n == 0)
		res[0] = '0';
	res[len + negative] = '\0';
	fillitoa(n, len, negative, res);
	return (res);
}
