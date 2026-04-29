#include "ft.printf.h"

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
