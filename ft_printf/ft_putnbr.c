#include "ft_printf.h"

void    ft_putnbr(int n, int *len)
{
    if (!len)
        return ;
    if (n == -2147483648)
        ft_putchar(n, len);
    else if(n < 0)
    {
        write(1, "-", 1);
        n *= -1;
        (*len)++;
        ft_putnbr(n, len);
    }
    else if(n >= 10)
    {
        ft_putnbr(n / 10, len);
        ft_putnbr(n % 10, len);
    }
    else
        ft_putchar(n + '0', len);
}