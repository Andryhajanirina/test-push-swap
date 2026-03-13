/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamiandr <mamiandr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 18:10:35 by mamiandr          #+#    #+#             */
/*   Updated: 2026/02/23 14:38:59 by mamiandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putptr(void *ptr)
{
	unsigned long int	addr;
	int					l;

	addr = (unsigned long int) ptr;
	l = 0;
	if (addr == 0)
		return (ft_putstr("(nil)"));
	l += ft_putstr("0x");
	l += ft_puthexa(addr, 'x');
	return (l);
}
