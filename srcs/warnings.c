#include "../inc/ft_printf.h"

void hashtag_warning(void)
{
	char *warning = "warning: repeated '#' flag in format\n";
	write(2, warning, ft_strlen(warning));
}

void plus_warning(void)
{
	char *warning = "warning: repeated '+' flag in format\n";
	write(2, warning, ft_strlen(warning));
}

void minus_warning(void)
{
	char *warning = "warning: repeated '-' flag in format\n";
	write(2, warning, ft_strlen(warning));
}

void space_warning(void)
{
	char *warning = "warning: repeated ' ' flag in format\n";
	write(2, warning, ft_strlen(warning));	
}

void point_warning(void)
{
	char *warning = "warning: repeated '.' flag in format\n";
	write(2, warning, ft_strlen(warning));
}

void zero_warning(void)
{
	char *warning = "warning: repeated '0' flag in format\n";
	write(2, warning, ft_strlen(warning));	
}

void check_warnings(t_flags *f)
{
	if (f->hashtag > 1)
		hashtag_warning();
	else if (f->plus > 1)
		plus_warning();
	else if (f->minus > 1)
		minus_warning();
	if (f->space > 1)
		space_warning();
	else if (f->point > 1)
		point_warning();
	else if (f->zero > 1)
		zero_warning();
}