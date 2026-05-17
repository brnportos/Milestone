#include "ft_printf.h"

void	isuphexa_fd(int fd, unsigned int nbr, int *len)
{
	char	*base;

	base = "0123456789ABCDEF";
	if (!len)
		return ;
	if (nbr > 15)
		isuphexa_fd(fd, nbr / 16, len);
	ft_putchar_fd(fd, base[nbr % 16], len);
}
