/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andry-ha <andry-ha@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 15:57:10 by andry-ha          #+#    #+#             */
/*   Updated: 2026/03/16 16:49:44 by andry-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	handle_precision(const char *str, int *i, va_list args)
{
	int		precision;
	double	val;

	precision = 0;
	(*i)++;
	while (str[*i] >= '0' && str[*i] <= '9')
	{
		precision = precision * 10 + (str[*i] - '0');
		(*i)++;
	}
	if (str[*i] == 'f')
	{
		val = va_arg(args, double);
		return (ft_print_float(val, precision));
	}
	return (write(1, &str[*i], 1));
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		i;
	int		count;

	if (!str)
		return (0);
	va_start(args, str);
	i = -1;
	count = 0;
	while (str[++i])
	{
		if (str[i] == '%' && str[i + 1])
		{
			i++;
			if (str[i] == '.')
				count += handle_precision(str, &i, args);
			else
				count += handle_format(str[i], args);
		}
		else
			count += write(1, &str[i], 1);
	}
	va_end(args);
	return (count);
}
