/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlence-l <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 19:46:20 by nlence-l          #+#    #+#             */
/*   Updated: 2023/03/03 17:28:47 by nlence-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

int main_loop(const char *format, t_flags *f, va_list args)
{
	char *flags;

	if (format[f->index] == '%')
	{
		f->index++;
		flags = get_flags_and_specifier(format, f);
		if (!flags)
			return (-1);
		parse_flags_get_info(flags, f);
		f->lenght += parser(args, format[f->index], f);
		f->index++;
		reset_flags(f);
		free(flags);
	}
	else
		f->lenght += print_char(format[f->index++]);
	if (f->lenght == -1)
		return (-1);
	return (0);
}

char *get_flags_and_specifier(const char *format, t_flags *f)
{
	int len;
	int i;
	char *flags;

	len = 0;
	i = f->index;
	while (format[i] && is_flag(format[i]))
	{
		i++;
		len++;
	}
	if (format[i] && is_specifier(format[i]))
		f->specifier = format[i];
	flags = (char *)malloc(sizeof(char) * (len + 1));
	if (!flags)
		return (NULL);
	i = 0;
	while (format[f->index] && is_flag(format[f->index]))
	{
		flags[i] = format[f->index];
		i++;
		f->index++;
	}
	flags[i] = '\0';
	return (flags);
}

void parse_flags_get_info(char *flags, t_flags *f)
{
	size_t i;

	i = 0;
	while (flags[i])
	{
		if (flags[i] == '#')
			f->hashtag++;
		else if (flags[i] == '+')
			f->plus++;
		else if (flags[i] == '-')
			f->minus++;
		else if (flags[i] == ' ')
			f->space++;
		else if (flags[i] == '0')
			f->zero++;
		else if (flags[i] == '.')
			f->point++;
		i++;
	}
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	t_flags f;

	if (!format)
		return (0);
	init_flags(&f);
	va_start(args, format);
	while (format[f.index])
	{
		if (main_loop(format, &f, args) == -1)
			return (-1);
	}
	va_end(args);
	return (f.lenght);
}