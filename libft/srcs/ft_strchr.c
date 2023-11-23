/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxime_pierrot <maxime_pierrot@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 21:12:13 by maxime_pier       #+#    #+#             */
/*   Updated: 2023/11/11 16:22:43 by maxime_pier      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	while (((char)c != *s) && *s)
		s++;
	if ((char)c == *s)
		return ((char *)s);
	else
		return (NULL);
}
