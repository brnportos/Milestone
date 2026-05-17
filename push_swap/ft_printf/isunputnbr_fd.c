#include "ft_printf.h"

void	isunputnbr_fd(int fd, unsigned int nbr, int *len)
{
	if (!len)
		return ;
	if (nbr >= 10)
		isunputnbr_fd(fd, nbr / 10, len);
	ft_putchar_fd(fd, nbr % 10 + '0', len);
}
