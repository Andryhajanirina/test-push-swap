/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamiandr <mamiandr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 18:10:11 by mamiandr          #+#    #+#             */
/*   Updated: 2026/02/23 14:57:06 by mamiandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_pfmanager(int c, va_list variadic_elm)
{
	int	l;

	l = 0;
	if (c == 'c')
		l += ft_putchar(va_arg(variadic_elm, int));
	else if (c == 's')
		l += ft_putstr(va_arg(variadic_elm, char *));
	else if (c == 'p')
		l += ft_putptr(va_arg(variadic_elm, void *));
	else if (c == 'i' || c == 'd')
		l += ft_putnbr(va_arg(variadic_elm, int));
	else if (c == 'u')
		l += ft_putnbr_u(va_arg(variadic_elm, unsigned int));
	else if (c == 'x' || c == 'X')
		l += ft_puthexa(va_arg(variadic_elm, unsigned int), c);
	else if (c == '%')
		l += ft_putchar('%');
	return (l);
}

int	ft_printf(const char *format, ...)
{
	int		l;
	int		i;
	va_list	arg;

	va_start(arg, format);
	i = 0;
	l = 0;
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1] != '\0')
		{
			l += ft_pfmanager(format[i + 1], arg);
			i++;
		}
		else
			l += ft_putchar(format[i]);
		i++;
	}
	va_end(arg);
	return (l);
}
