#include "ft_printf.h"

static void	ft_putlowhexa(int fd, unsigned long long nbr, int *len)
{
	char	*base;

	base = "0123456789abcdef";
	if (!len)
		return ;
	if (nbr > 15)
		ft_putlowhexa(fd, nbr / 16, len);
	ft_putchar(fd, base[nbr % 16], len);
}


