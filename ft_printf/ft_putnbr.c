/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: portos <portos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/01 19:41:46 by portos            #+#    #+#             */
/*   Updated: 2026/05/05 21:12:56 by portos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void    ft_putnbr(int n, int *len)
{
    if (!len)
        return ;
    if (n == -2147483648)
    {
        ft_putstr("-2147483648", len);
        return ;
    }
    else if(n < 0)
    {
        ft_putchar('-', len);
        n *= -1;
    }
    else if(n >= 10)
        ft_putnbr(n / 10, len);
    ft_putchar((n % 10) + '0', len);
}