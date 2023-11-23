/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxime_pierrot <maxime_pierrot@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 21:40:04 by mpierrot          #+#    #+#             */
/*   Updated: 2023/11/11 19:24:03 by maxime_pier      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int	i;
	int	j;
	int	z;

	i = 0;
	j = 1;
	z = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == 45)
		j *= -1;
	if (str[i] == 45 || str[i] == 43)
		i++;
	while (str[i] >= 48 && str[i] <= 57)
	{
		z = z * 10 + (str[i] - '0');
		i++;
	}
	z *= j;
	return (z);
}
