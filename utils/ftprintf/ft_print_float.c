/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_float.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andry-ha <andry-ha@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/13 16:44:18 by andry-ha          #+#    #+#             */
/*   Updated: 2026/03/13 16:53:37 by andry-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static long ft_power10(int n)
{
    long result = 1;
    while (n-- > 0)
        result *= 10;
    return result;
}

int ft_print_float(double n, int precision)
{
    int count = 0;
    long integer;
    double decimal;
    int i;
    char digit;

    // gérer le signe
    if (n < 0)
    {
        ft_putchar_fd('-', 1);
        n = -n;
        count++;
    }

    // partie entière et fractionnaire
    integer = (long)n;
    decimal = n - integer;

    count += ft_print_nbr(integer);
    ft_putchar_fd('.', 1);
    count++;

    // multiplier la partie fractionnaire pour la précision et arrondir
	decimal = decimal * ft_power10(precision) + 0.5;
    long frac = (long)decimal;

    long div = ft_power10(precision - 1);
    i = 0;
    while ( i < precision)
    {
        digit = (frac / div) % 10 + '0';
        count += write(1, &digit, 1);
        div /= 10;
        i++;
    }

    return count;
}