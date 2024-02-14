#include "../inc/ft_printf.h"

void init_flags(t_flags *f)
{
	f->index = 0;
	f->lenght = 0;
	f->hashtag = 0;
    f->space = 0;
    f->plus = 0;
    f->minus = 0;
    f->zero = 0;
    f->point = 0;
}

void reset_flags(t_flags *f)
{
	f->hashtag = 0;
    f->space = 0;
    f->plus = 0;
    f->minus = 0;
    f->zero = 0;
    f->point = 0;
}

int is_specifier(char c)
{
	if (c == 'c' || c == 's' || c == 'p' || c == 'd'
		|| c == 'i' || c == 'u' || c == 'x' || c == 'X' || c == '%')
		return (1);
	return (0);
}

int is_flag(char c)
{
	if (c == ' ' || c == '#' || c == '+' || c == '-' || c == '.' || c == '0')
		return (1);
	return (0);
}

size_t ft_strlen(char *str)
{
	size_t len;

	while (*str)
	{
		str++;
		len++;
	}
	return (len);
}