#include "ft_printf.h"

void    ft_is_unsigned_nbr(unsigned int num, int *len)
{
    if (num >= 10)
    {
        ft_is_unsigned_nbr(n / 10, len);
        ft_is_unsigned_nbr(n % 10, len);
    }
    else
        ft_putchar(n + '0', len);
}