/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_usefulfonc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpierrot <mpierrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 22:04:26 by mpierrot          #+#    #+#             */
/*   Updated: 2024/01/22 20:32:01 by mpierrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_putstr(char *s)
{
	int	i;

	if (!s)
		return (ft_putstr("(null)"), 6);
	i = 0;
	while (s[i])
		i += ft_putchar(s[i]);
	return (i);
}

int	ft_putptr(void *ptr)
{
	unsigned long	i;
	int				res;

	i = (unsigned long) ptr;
	res = 0;
	if (i > 15)
		res += ft_putptr((void *)(i / 16));
	res += ft_putchar("0123456789abcdef"[i % 16]);
	return (res);
}

/*int	ft_putnbr(int n)
{
	long int	nb;
	int			res;

	res = 0;
	nb = n;
	if (nb == -2147483648)
	{
		write(1, "-2147483648", 11);
		return (res++);
	}
	if (nb < 0)
	{
		nb = nb * -1;
		res++;
		write(1, "-", 1);
	}
	if (nb > 9)
	{
		res += ft_putnbr(nb / 10);
		res += ft_putnbr(nb % 10);
	}
	if (nb >= 0 && nb <= 9)
		return (ft_putchar(nb + '0'));
	return (res);
}*/

int ft_putnbr(int n)
{
	char *tmp;
	int res;
	
	res = 0;
	tmp = ft_itoa(n);
    res += ft_putstr(tmp);
	free(tmp);
	return (res);

}

int	ft_unputnbr(unsigned int nb)
{
	int	res;

	res = 0;
	if (nb > 9)
	{
		res += ft_unputnbr(nb / 10);
		res += ft_unputnbr(nb % 10);
	}
	if (nb >= 0 && nb <= 9)
		return (ft_putchar(nb + '0'));
	return (res);
}

int	ft_puthexa(unsigned int nb, char *hexa)
{
	int	res;

	res = 0;
	if (nb >= 16)
	{
		res += ft_puthexa(nb / 16, hexa);
		res += ft_puthexa(nb % 16, hexa);
	}
	else
		res += ft_putchar(hexa[nb]);
	return (res);
}
