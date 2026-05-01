#ifndef FT_PRINTF_H
#define TF_PRINTF_H
#include <unistd.h>
#include <stdarg.h>

void    ft_putchar(char c, int *len);
void    ft_putstr(char *str, int *len);
void    is_address(void *ptr, int *len);
void    ft_putnbr(int n, int *len);
void    ft_is_unsigned_nbr(unsigned int num, int *len);
void    ft_islowhexadecimal(unsigned int num, int *len);
void    ft_isuphexadecimal(unsigned int num, int *len);
void    ft_is_conversion(va_list *ap, char *str, int *len);

#endif
