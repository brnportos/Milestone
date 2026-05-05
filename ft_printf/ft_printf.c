/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: portos <portos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/02 20:02:09 by portos            #+#    #+#             */
/*   Updated: 2026/05/05 20:53:41 by portos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *str, ...)
{
    va_list ap;
    int len;

    if (!str)
        return (-1);
    len = 0;
    va_start(ap, str);
    while (*str)
    {
        if (*str == '%')
        {
            if (!*(str + 1))
            {
                va_end(ap);
                return (-1);
            }
            str++;
            ft_is_conversion(&ap, (char *)str, &len);
        }
        else
            ft_putchar(*str, &len);
        str++;
    }
    va_end(ap);
    return (len);
}
