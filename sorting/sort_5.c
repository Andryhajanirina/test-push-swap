/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andry-ha <andry-ha@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 15:13:44 by andry-ha          #+#    #+#             */
/*   Updated: 2026/03/15 13:50:45 by andry-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sorting.h"

void	sort_5(t_stack **a, t_stack **b, int print, int *count)
{
	while (stack_size(*a) > 3)
	{
		if ((*a)->index == 0 || (*a)->index == 1)
			pb(a, b, print, count);
		else
			ra(a, print, count);
	}
	sort_3(a, print, count);
	/* remettre les deux éléments */
	if (stack_size(*b) > 1 && (*b)->index < (*b)->next->index)
		sb(b, print, count);
	while (*b)
		pa(a, b, print, count);
}