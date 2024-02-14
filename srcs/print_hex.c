/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlence-l <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 19:43:37 by nlence-l          #+#    #+#             */
/*   Updated: 2023/03/03 17:26:25 by nlence-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

int	hex_len(unsigned	int n)
{
	int	len;

	len = 0;
	while (n != 0)
	{
		len++;
		n = n / 16;
	}
	return (len);
}

int	get_hex(unsigned int n, const char c)
{
	int	x;

	x = 0;
	if (n >= 16)
	{
		if (get_hex(n / 16, c) == -1)
			return (-1);
		if (get_hex(n % 16, c) == -1)
			return (-1);
	}
	else
	{
		if (n <= 9)
			x = print_char(n + '0');
		else
		{
			if (c == 'x')
				x = print_char(n - 10 + 'a');
			if (c == 'X')
				x = print_char(n - 10 + 'A');
		}
		if (x == -1)
			return (-1);
	}
	return (hex_len(n));
}

int	print_hex(unsigned int n, const char c, t_flags *f)
{
	int res;

	res = 0;
	if (n == 0)
	{
		if (f->hashtag && c == 'x')
			res += write(1, "0x", 2);
		else if (f->hashtag && c == 'X')
			res += write(1, "0X", 2);
		res += print_char('0');
		return (res);
	}
	else
	{
		if (f->hashtag && c == 'x')
			res += write(1, "0x", 2);
		else if (f->hashtag && c == 'X')
			res += write(1, "0X", 2);
		res += 	get_hex(n, c);
		return (res);
	}
}
