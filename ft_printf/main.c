#include "ft_printf.h"
#include <stdio.h>
int	main()
{
	ft_printf("%c %s %p %d %i %u %x %X\n", 'c', "Helle", &main, -2147483648, 2147483647, 4294967296, 10, 10); 
}
