/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_u.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamiandr <mamiandr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 18:10:29 by mamiandr          #+#    #+#             */
/*   Updated: 2026/02/23 14:57:23 by mamiandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_u(unsigned int nbr)
{
	unsigned long	n;
	int				l;

	n = (unsigned long) nbr;
	l = 0;
	if (n < 0)
	{
		l += ft_putchar('-');
		n = -n;
	}
	if (n >= 10)
		l += ft_putnbr_u(n / 10);
	l += ft_putchar((n % 10) + '0');
	return (l);
}
