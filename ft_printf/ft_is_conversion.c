/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_conversion.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: portos <portos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/01 19:13:01 by portos            #+#    #+#             */
/*   Updated: 2026/05/05 20:39:03 by portos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void    ft_is_conversion(va_list *ap, const char *str, int *len)
{
    if (!ap || !str || !len)
        return ;
    if (*str == 'c')
        ft_putchar(va_arg(*ap, int), len);
    else if (*str == 's')
        ft_putstr(va_arg(*ap, char *), len);
    else if (*str == 'p')
        is_address(va_arg(*ap, void *), len);
    else if (*str == 'd' || *str == 'i')
        ft_putnbr(va_arg(*ap, int), len);
    else if (*str == 'u')
        ft_is_unsigned_nbr(va_arg(*ap, unsigned int), len);
    else if (*str == 'X')
        ft_isuphexadecimal(va_arg(*ap, unsigned int), len);
    else if (*str == 'x')
        ft_islowhexadecimal(va_arg(*ap, unsigned int), len);
    else if (*str == '%')
        ft_putchar(*str, len);
}
