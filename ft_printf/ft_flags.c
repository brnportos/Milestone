#include "ft_printf.h"

void    init_flags(t_flags *f)
{
    f->minus = 0;
    f->zero = 0;
    f->dot = 0;
    f->hash = 0;
    f->plus = 0;
    f->space = 0;
    f->width = 0;
    f->precision = -1;
    f->type = 0;
}

int is_flag(char c)
{
    return(c == '-' || c == '0' || c == '.' || c == '#' || c == '+' || c == ' ');
}

void	parse_flags(const char *str, t_flags *f, const char **end)
{
    while (*str)
    {
        if (*str == '-')
            f->minus = 1;
        else if (*str == '0')
            f->zero = 1;
        else if (*str == '#')
            f->hash = 1;
        else if (*str == '+')
            f->plus = 1;
        else if (*str == ' ')
            f->space = 1;
        else
            break ;
        str++;
    }
    *end = str;
}

void	parse_width(const char *str, t_flags *f, const char **end, va_list *ap)
{
    int n;

    n = 0;
    if (*str == '*')
    {
        n = va_arg(*ap, int);
        if (n < 0)
        {
            f->minus = 1;
            n = -n;
        }
        f->width = n;
        str++;
    }
    else
    {
        while (*str >= '0' && *str <= '9')
        {
            n = n * 10 + (*str - '0');
            str++;
        }
        f->width = n;
    }
    *end = str;
}

void	parse_precision(const char *str, t_flags *f, const char **end, va_list *ap)
{
    int n;

    if (*str != '.')
    {
        *end = str;
        return ;
    }
    str++;
    n = 0;
    if (*str == '*')
    {
        n = va_arg(*ap, int);
        if (n < 0)
            n = -1;
        f->precision = n;
        str++;
    }
    else
    {
        while (*str >= '0' && *str <= '9')
        {
            n = n * 10 + (*str - '0');
            str++;
        }
        f->precision = n;
    }
    *end = str;
}

void    resolve_flags(t_flags *f)
{
    if (f->minus)
        f->zero = 0;
    if (f->plus)
        f->space = 0;
}
