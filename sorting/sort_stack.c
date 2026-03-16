/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andry-ha <andry-ha@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/08 16:14:04 by andry-ha          #+#    #+#             */
/*   Updated: 2026/03/16 13:37:52 by andry-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sorting.h"

void	sort_stack(t_stack **a, t_stack **b, t_config *cfg)
{
	int	size;

	size = stack_size(*a);
	if (size <= 1)
		return ;
	if (size == 2)
	{
		if ((*a)->value > (*a)->next->value)
			sa(a, cfg);
	}
	else if (size == 3)
	{
		ft_printf("sort_3\n");
		sort_3(a, cfg);
	}
	else if (size <= 5)
	{
		ft_printf("sort_5\n");
		sort_5(a, b, cfg);
	}
	else
	{
		ft_printf("radix_sort\n");
		radix_sort(a, b, cfg);
	}
}

