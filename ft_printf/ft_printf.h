#ifndef FT_PRINTF_H
# define FT_PRINTF_H
#include <unistd.h>
#include <stdarg.h>

typedef struct s_flags
{
    int minus;
    int zero;
    int dot;
    int hash;
    int plus;
    int space;
    int width;
    int precision;
    char type;
}   t_flags;

void    ft_putchar(char c, int *len);
void    ft_putstr(char *str, int *len);
void    is_address(void *ptr, int *len);
void    ft_putnbr(int n, int *len);
void    ft_is_unsigned_nbr(unsigned int num, int *len);
void    ft_islowhexadecimal(unsigned int num, int *len);
void    ft_isuphexadecimal(unsigned int num, int *len);
void    ft_is_conversion(va_list *ap, const char *str, int *len);
int     ft_printf(const char *str, ...);

#endif
