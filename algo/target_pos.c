/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   target_pos.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andry-ha <andry-ha@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/01 15:05:20 by andry-ha          #+#    #+#             */
/*   Updated: 2026/04/01 15:57:54 by andry-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "algo.h"

/* int	target_pos(t_stack *a, int idx)
{
	t_stack	*tmp;
	int		pos;
	int		best_pos;
	int		best_diff;

	tmp = a;
	pos = 0;
	best_pos = 0;
	best_diff = a->index - idx;
	if (best_diff <= 0)
		best_diff = 2147483647;
	while (tmp)
	{
		int diff = tmp->index - idx;
		if (diff > 0 && diff < best_diff)
		{
			best_diff = diff;
			best_pos = pos;
		}
		pos++;
		tmp = tmp->next;
	}
	if (best_diff == 2147483647)
		return (find_min_pos(a));
	return (best_pos);
} */

static int	is_between(int prev, int curr, int b_index)
{
	return (prev < b_index && b_index < curr);
}

static int	find_gap_pos(t_stack *a, int b_index)
{
	int		pos;
	t_stack	*prev;

	pos = 1;
	prev = a;
	a = a->next;
	while (a)
	{
		if (is_between(prev->index, a->index, b_index))
			return (pos);
		prev = a;
		a = a->next;
		pos++;
	}
	return (-1);
}

int	target_pos(t_stack *a, int b_index)
{
	int	pos;

	if (b_index < find_min(a)->index
		|| b_index > find_max(a)->index)
		return (find_min_pos(a));
	pos = find_gap_pos(a, b_index);
	if (pos != -1)
		return (pos);
	return (0);
}
