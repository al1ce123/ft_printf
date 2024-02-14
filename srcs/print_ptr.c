/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlence-l <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 14:09:35 by nlence-l          #+#    #+#             */
/*   Updated: 2023/03/01 14:11:05 by nlence-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

int	ptr_len(unsigned long long n)
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

void	get_ptr(unsigned long long n)
{
	if (n >= 16)
	{
		get_ptr(n / 16);
		get_ptr(n % 16);
	}
	else
	{
		if (n <= 9)
			print_char(n + '0');
		else
			print_char(n - 10 + 'a');
	}
}

int	print_ptr(unsigned long long n)
{
	int	len;

	len = 0;
	len += write(1, "0x", 2);
	if (len == -1)
		return (-1);
	if (n == 0)
	{
		len += write(1, "0", 1);
		if (len == -1)
			return (-1);
	}
	else
	{
		get_ptr(n);
		len += ptr_len(n);
	}
	return (len);
}
