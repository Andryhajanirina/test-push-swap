/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_float.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andry-ha <andry-ha@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/13 16:44:18 by andry-ha          #+#    #+#             */
/*   Updated: 2026/03/17 12:58:44 by andry-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static long	ft_power10(int n)
{
	long	result;

	result = 1;
	while (n-- > 0)
		result *= 10;
	return (result);
}

static int	print_decimals(double decimal, int precision)
{
	long	frac;
	long	div;
	int		count;
	char	digit;

	count = 0;
	frac = (long)(decimal * ft_power10(precision) + 0.5);
	div = ft_power10(precision - 1);
	while (precision-- > 0)
	{
		digit = (frac / div) % 10 + '0';
		count += write(1, &digit, 1);
		div /= 10;
	}
	return (count);
}

int	ft_print_float(double n, int precision)
{
	int		count;
	long	integer;
	double	decimal;

	count = 0;
	if (n < 0)
	{
		count += write(1, "-", 1);
		n = -n;
	}
	integer = (long)n;
	decimal = n - integer;
	count += ft_print_nbr(integer);
	count += write(1, ".", 1);
	count += print_decimals(decimal, precision);
	return (count);
}
