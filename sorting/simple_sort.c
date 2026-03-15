/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andry-ha <andry-ha@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/13 13:35:56 by andry-ha          #+#    #+#             */
/*   Updated: 2026/03/15 14:17:08 by andry-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sorting.h"

/* Positionner l’élément le plus petit en haut avec rotations */
static void move_min_top(t_stack **a, int print, int *count)
{
	t_stack *min = find_min(*a);
	int pos = 0;
	t_stack *tmp = *a;

	while (tmp && tmp != min)
	{
		tmp = tmp->next;
		pos++;
	}
	int size = stack_size(*a);
	if (pos <= size / 2)
	{
		while (pos-- > 0)
			ra(a, print, count);
	}
	else
	{
		pos = size - pos;
		while (pos-- > 0)
			rra(a, print, count);
	}
}

void	simple_sort(t_stack **a, t_stack **b, int print, int *count)
{
	while (stack_size(*a) > 3)
	{
		move_min_top(a, print, count);
		pb(a, b, print, count);
	}
	sort_3(a, print, count);
	while (*b)
		pa(a, b, print, count);
}
