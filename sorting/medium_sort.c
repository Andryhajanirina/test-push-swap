/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andry-ha <andry-ha@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/13 13:51:31 by andry-ha          #+#    #+#             */
/*   Updated: 2026/03/19 16:44:06 by andry-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sorting.h"

static int	find_max_pos(t_stack *b)
{
	int	max;
	int	pos;
	int	i;

	if (!b)
		return (-1);
	max = b->index;
	pos = 0;
	i = 0;
	while (b)
	{
		if (b->index > max)
		{
			max = b->index;
			pos = i;
		}
		b = b->next;
		i++;
	}
	return (pos);
}

static void	move_max_top(t_stack **b, t_config *cfg)
{
	int	pos;
	int	b_size;

	pos = find_max_pos(*b);
	b_size = stack_size(*b);
	if (pos <= b_size / 2)
	{
		while (pos--)
			rb(b, cfg);
	}
	else
	{
		pos = b_size - pos;
		while (pos--)
			rrb(b, cfg);
	}
}

static int	ft_sqrt_ceil(int nb)
{
	int	i;

	i = 1;
	while (i * i < nb)
		i++;
	return (i);
}

void	medium_sort(t_stack **a, t_stack **b, t_config *cfg)
{
	int	i;
	int	chunk;

	i = 0;
	chunk = ft_sqrt_ceil(stack_size(*a));
	while (*a)
	{
		if ((*a)->index <= i)
		{
			pb(a, b, cfg);
			rb(b, cfg);
			i++;
		}
		else if ((*a)->index <= i + chunk && ++i)
			pb(a, b, cfg);
		else
			ra(a, cfg);
	}
	while (*b)
	{
		move_max_top(b, cfg);
		pa(a, b, cfg);
	}
}
