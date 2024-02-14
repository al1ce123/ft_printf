/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_u.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlence-l <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 19:45:35 by nlence-l          #+#    #+#             */
/*   Updated: 2023/03/03 17:28:21 by nlence-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

int	ulen(unsigned int n)
{
	int	res;

	res = 1;
	while (n / 10 != 0)
	{
		n /= 10;
		res *= 10;
	}
	return (res);
}

int	print_u(unsigned int n)
{
	int	len;
	int	res;

	len = ulen(n);
	res = 0;
	while (len != 0)
	{
		res += print_char(n / len + '0');
		if (res == -1)
			return (-1);
		n = n % len;
		len = len / 10;
	}
	return (res);
}
