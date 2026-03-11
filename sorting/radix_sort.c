/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andry-ha <andry-ha@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 15:13:44 by andry-ha          #+#    #+#             */
/*   Updated: 2026/03/11 16:10:18 by andry-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "../push_swap.h"
#include "sorting.h"

/* void buble_sort(int a[], int length)
{
    int 		i;
    int 		j;
    int 		tmp;
	static int	swaped;
    
    i = 0;
    while (i < length)
    {
        j = 0;
		swaped = 0;
        while (j < (length - 1 - i))
        {
            if (a[j] > a[j + 1])
            {
                tmp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = tmp;
            }
			swaped = 1;
            j++;
        }
		if (swaped == 1)
			break;
        i++;
    }
} */

static int	get_max_bits(int size)
{
	int max;
	int bits;

	max = size - 1;
	bits = 0;
	while ((max >> bits) != 0)
		bits++;
	return (bits);
}

void radix_sort(t_stack **a, t_stack **b, int print)
{
	int i, j;
	int size = stack_size(*a);
	int max_bits = 0;

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