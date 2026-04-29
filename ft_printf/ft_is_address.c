#include "ft_printf.h"

static void low_hexa(unsigned long long nbr, int *len)
{
    char    *base;

    if (!len)
        return ;
    base = "0123456789abcdef";
    if (nbr > 15)
        low_hexa(nbr / 16, len);
    ft_putchar(base[nbr % 16], len);
}

void    is_address(void *ptr, int *len)
{
    unsigned long long  address;

    if (!ptr || !len)
    {
        ft_putstr("(nil)", len);
        return ;
    }
    address = (unsigned long long)ptr;
    ft_putstr("0x", len);
    low_hexa(address, len);
}
