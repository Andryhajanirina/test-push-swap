/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andry-ha <andry-ha@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 15:13:44 by andry-ha          #+#    #+#             */
/*   Updated: 2026/03/16 13:36:47 by andry-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sorting.h"

void	sort_3(t_stack **a, t_config *cfg)
{
	int	first;
	int	second;
	int	third;

	first = (*a)->index;
	second = (*a)->next->index;
	third = (*a)->next->next->index;
	// 1, 0, 2
	if (first > second && first < third && second < third)
		sa(a, cfg);
	//2, 1, 0
	else if (first > second && second > third && first > third)
	{
		sa(a, cfg);
		rra(a, cfg);
	}
	//2, 0, 1
	//3 > 1 < 2
	else if (first > second && second < third && first > third)
		ra(a, cfg);
	//1, 2, 0 
	else if (first < second && first > third && second > third)
		rra(a, cfg);
	//0, 2, 1
	else if (first < second && second > third)
	{
		sa(a, cfg);
		ra(a, cfg);
	}
}
