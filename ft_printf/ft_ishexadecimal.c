/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ishexadecimal.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: portos <portos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/01 19:41:30 by portos            #+#    #+#             */
/*   Updated: 2026/05/01 19:44:48 by portos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void    ft_islowhexadecimal(unsigned int num, int *len)
{
    char    *base;

    if (!len)
        return ;
    base = "0123456789abcdef";
    if (num > 15)
        ft_islowhexadecimal(num / 15, len);
    ft_putchar(base[num % 16], len);
}

void    ft_isuphexadecimal(unsigned int num, int *len)
{
    char    *base;

    if (!len)
        return ;
    base = "0123456789ABCDEF";
    if (num > 15)
        ft_isuphexadecimal(num / 10, len);
    ft_putchar(base[num % 16], len);
}
