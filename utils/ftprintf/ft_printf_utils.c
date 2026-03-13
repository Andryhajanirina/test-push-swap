/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andry-ha <andry-ha@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 13:22:05 by andry-ha          #+#    #+#             */
/*   Updated: 2026/03/12 15:31:30 by andry-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_put_hex(unsigned int n, char *base)
{
	int		count;

	count = 0;
	if (n >= 16)
		count += ft_put_hex(n / 16, base);
	count += write(1, &base[n % 16], 1);
	return (count);
}

int	ft_print_hex(unsigned int n, char *base)
{
	return (ft_put_hex(n, base));
}

int	ft_print_nbr(int n)
{
	long	nb;
	int		count;

	count = 0;
	nb = (long)n;
	if (nb < 0)
	{
		count += write(1, "-", 1);
		nb = -nb;
	}
	if (nb >= 10)
		count += ft_print_nbr(nb / 10);
	count += write(1, &"0123456789"[nb % 10], 1);
	return (count);
}

static int	ft_put_ptr(unsigned long n)
{
	int		count;
	char	*base;

	base = "0123456789abcdef";
	count = 0;
	if (n >= 16)
		count += ft_put_ptr(n / 16);
	count += write(1, &base[n % 16], 1);
	return (count);
}

int	ft_print_ptr(void *ptr)
{
	int	count;

	if (!ptr)
		return (write(1, "(nil)", 5));
	count = 0;
	count += write(1, "0x", 2);
	count += ft_put_ptr((unsigned long)ptr);
	return (count);
}
