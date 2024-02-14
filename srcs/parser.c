/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlence-l <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 19:42:13 by nlence-l          #+#    #+#             */
/*   Updated: 2023/02/28 19:51:45 by nlence-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

int	parser(va_list args, char c, t_flags *f)
{
	int	len;

	len = 0;
	if (c == 'c')
		len += print_char(va_arg(args, int));
	else if (c == 's')
		len += print_str(va_arg(args, char *));
	else if (c == 'd' || c == 'i')
		len += print_nbr(va_arg(args, int));
	else if (c == 'u')
		len += print_u(va_arg(args, unsigned int));
	else if (c == 'p')
		len += print_ptr(va_arg(args, unsigned long));
	else if (c == 'x' || c == 'X')
		len += print_hex(va_arg(args, unsigned int), c, f);
	else if (c == '%')
		len += print_percent();
	return (len);
}
