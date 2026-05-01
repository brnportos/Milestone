/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_unsigned_nbr.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: portos <portos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/01 19:41:22 by portos            #+#    #+#             */
/*   Updated: 2026/05/01 19:43:35 by portos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void    ft_is_unsigned_nbr(unsigned int num, int *len)
{
    if (num >= 10)
    {
        ft_is_unsigned_nbr(num / 10, len);
        ft_is_unsigned_nbr(num % 10, len);
    }
    else
        ft_putchar(num + '0', len);
}