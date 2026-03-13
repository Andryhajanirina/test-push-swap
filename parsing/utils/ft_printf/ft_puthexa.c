/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamiandr <mamiandr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 18:10:22 by mamiandr          #+#    #+#             */
/*   Updated: 2026/02/23 14:58:25 by mamiandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthexa(unsigned long int n, char b)
{
	int		l;
	char	*base;

	l = 0;
	if (b == 'x')
		base = "0123456789abcdef";
	else
		base = "0123456789ABCDEF";
	if (n >= 16)
		l += ft_puthexa((n / 16), b);
	l += ft_putchar(base[n % 16]);
	return (l);
}
