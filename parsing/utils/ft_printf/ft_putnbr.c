/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamiandr <mamiandr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 18:10:32 by mamiandr          #+#    #+#             */
/*   Updated: 2026/02/23 14:57:15 by mamiandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int nbr)
{
	long	n;
	int		l;

	n = (long) nbr;
	l = 0;
	if (n < 0)
	{
		l += ft_putchar('-');
		n = -n;
	}
	if (n >= 10)
		l += ft_putnbr(n / 10);
	l += ft_putchar((n % 10) + '0');
	return (l);
}
