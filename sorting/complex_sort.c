/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andry-ha <andry-ha@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 13:11:17 by andry-ha          #+#    #+#             */
/*   Updated: 2026/04/01 16:20:30 by andry-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sorting.h"
#include "../algo/algo.h"

static void	final_rotate(t_stack **a, t_config *cfg)
{
	int	pos;
	int	size;

	pos = find_min_pos(*a);
	size = stack_size(*a);
	if (pos <= size / 2)
		while (pos--)
			ra(a, cfg);
	else
		while (pos++ < size)
			rra(a, cfg);
}

void	complex_sort(t_stack **a, t_stack **b, t_config *cfg)
{
	int	size;
	int	limit;

	size = stack_size(*a);
	limit = size - 3;
	while (stack_size(*a) > 3)
	{
		if ((*a)->index < limit)
			pb(a, b, cfg);
		else
			ra(a, cfg);
	}
	sort_3(a, cfg);
	while (*b)
		best_move(a, b, cfg);
	final_rotate(a, cfg);
}
