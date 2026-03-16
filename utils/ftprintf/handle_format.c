/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_format.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andry-ha <andry-ha@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 17:31:13 by andry-ha          #+#    #+#             */
/*   Updated: 2026/03/16 16:54:50 by andry-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_print_char(int c)
{
	ft_putchar_fd(c, 1);
	return (1);
}

static int	ft_print_str(char *str)
{
	if (!str)
		return (write(1, "(null)", 6));
	return (write(1, str, ft_strlen(str)));
}

static int	ft_print_unsigned(unsigned int n)
{
	unsigned int	count;

	count = 0;
	if (n >= 10)
		count += ft_print_unsigned(n / 10);
	count += write(1, &"0123456789"[n % 10], 1);
	return (count);
}

int	handle_format(const char format, va_list args)
{
	if (format == 'c')
		return (ft_print_char(va_arg(args, int)));
	else if (format == 's')
		return (ft_print_str(va_arg(args, char *)));
	else if (format == 'd' || format == 'i')
		return (ft_print_nbr(va_arg(args, int)));
	else if (format == 'f')
		return (ft_print_float(va_arg(args, double), 6));
	else if (format == 'u')
		return (ft_print_unsigned(va_arg(args, unsigned int)));
	else if (format == 'x')
		return (ft_print_hex(va_arg(args, unsigned int), "0123456789abcdef"));
	else if (format == 'X')
		return (ft_print_hex(va_arg(args, unsigned int), "0123456789ABCDEF"));
	else if (format == 'p')
		return (ft_print_ptr(va_arg(args, void *)));
	else if (format == '%')
		return (ft_print_char('%'));
	else
		return (ft_print_char('%') + ft_print_char(format));
	return (0);
}
