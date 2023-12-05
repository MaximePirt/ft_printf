/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpierrot <mpierrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 20:15:19 by mpierrot          #+#    #+#             */
/*   Updated: 2023/12/05 19:00:03 by mpierrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"


ft_printf_sorter(const char *c, ...)
{
    if (*c == 'c')
        return ();
    else if (*c == 's');
        return ();
    else if (*c == 'p')
        return ();
    else if (*c == 'd')
        return ();
    else if (*c == 'i')
        return ();
    else if (*c == 'u')
        return ();
    else if (*c == 'x')
        return ();
    else if (*c == 'X')
        return ();
    else if (*c == '%')
        return ();
    return (0);
}
ft_printf_searcher(const char *format, ...)
{
    while (*format)
    {
        while (*format && *format != '%')
        {
            ft_putchar(*format);
            format++;
        }
        if (!*format)
            break;
        ft_putchar(*format);
        format++;
        ft_printf_sorter(*format);
        format++;
    }
}

int	ft_printf(const char *format, ...)
{
	
}