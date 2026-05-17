#include "ft_printf.h"

void	islowhexa_fd(int fd, unsigned int nbr, int *len)
{
	char	*base;

	base = "0123456789abcdef";
	if (!len)
		return ;
	if (nbr > 15)
		islowhexa_fd(fd, nbr / 16, len);
	ft_putchar_fd(fd, base[nbr % 16], len);
}
