/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_unsigned_nbr.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: portos <portos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/01 19:41:22 by portos            #+#    #+#             */
/*   Updated: 2026/05/05 20:41:37 by portos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void    ft_is_unsigned_nbr(unsigned int num, int *len)
{
    if (!len)
        return ;
    if (num >= 10)
        ft_is_unsigned_nbr(num / 10, len);
    ft_putchar((num % 10) + '0', len);
}