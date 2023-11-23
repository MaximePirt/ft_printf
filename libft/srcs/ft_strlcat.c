/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxime_pierrot <maxime_pierrot@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 15:16:29 by mpierrot          #+#    #+#             */
/*   Updated: 2023/11/11 15:32:40 by maxime_pier      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dstlen;
	size_t	srclen;
	size_t	total_len;
	size_t	i;

	if (!dst && !dstsize)
		return (ft_strlen(src));
	dstlen = ft_strlen(dst);
	srclen = ft_strlen(src);
	total_len = dstlen + srclen;
	i = 0;
	if (dstsize <= dstlen)
		return (dstsize + srclen);
	while (src[i] && (dstlen + i + 1) < dstsize)
	{
		dst[dstlen + i] = src[i];
		i++;
	}
	dst[dstlen + i] = '\0';
	return (total_len);
}
