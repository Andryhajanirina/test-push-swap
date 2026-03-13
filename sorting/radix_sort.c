/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andry-ha <andry-ha@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 15:13:44 by andry-ha          #+#    #+#             */
/*   Updated: 2026/03/13 17:38:52 by andry-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sorting.h"

static int	get_max_bits(int size)
{
	int	max;
	int	bits;

	max = size - 1;
	bits = 0;
	while ((max >> bits) != 0)
		bits++;
	return (bits);
}

void	radix_sort(t_stack **a, t_stack **b, int print)
{
	int	i;
	int	j;
	int	size;
	int	max_bits;

	size = stack_size(*a);
	i = 0;
	max_bits = get_max_bits(size);
	while (i < max_bits)
	{
		j = 0;
		while (j < size)
		{
			/**
			 * 1️⃣ on décale les bits
			 * 2️⃣ on regarde seulement le dernier bit
			 * 0110 & 0001 = 0
			 */
			//Equivalent : ((((*a)->index / 2^i) % 2) == 0)
			if ((((*a)->index >> i) & 1) == 0)
				pb(a, b, print);
			else
				ra(a, print);
			j++;
		}
		while (*b)
			pa(a, b, print);
		i++;
	}
}
