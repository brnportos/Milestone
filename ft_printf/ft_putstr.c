/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: portos <portos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/01 19:41:51 by portos            #+#    #+#             */
/*   Updated: 2026/05/05 20:19:17 by portos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void    ft_putstr(char *str, int *len)
{
    int i;

    i = 0;
    if (!len)
        return ;
    if (!str)
    {
        ft_putstr("(null)", len);
        return ;
    }
    while (str[i])
    {
        ft_putchar(str[i], len);
        i++;
    }
}
