/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andry-ha <andry-ha@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 15:13:44 by andry-ha          #+#    #+#             */
/*   Updated: 2026/03/20 09:21:59 by andry-ha         ###   ########.fr       */
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

void	radix_sort(t_stack **a, t_stack **b, t_config *cfg)
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
		while (j++ < size)
		{
			if ((((*a)->index >> i) & 1) == 0)
				pb(a, b, cfg);
			else
				ra(a, cfg);
		}
		while (*b)
			pa(a, b, cfg);
		i++;
	}
}

void	radix_sort_2bits(t_stack **a, t_stack **b, t_config *cfg)
{
	int	i;
	int	j;
	int	size;
	int	max_bits;
	int	val;

	size = stack_size(*a);
	i = 0;
	max_bits = get_max_bits(size);
	while (i < max_bits)
	{
		j = 0;
		while (j++ < size)
		{
			val = ((*a)->index >> i) & 3;
			if (val == 0)
				ra(a, cfg);
			else
				pb(a, b, cfg);
		}
		while (*b)
			pa(a, b, cfg);
		i += 2;
	}
}
