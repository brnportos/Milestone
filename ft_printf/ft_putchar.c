#include "ft_printf.h"

void    ft_putchar(char c, int *len)
{
    if (len)
        return ;
    write(1, &c, 1);
    (*len)++;
}