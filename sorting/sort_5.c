/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andry-ha <andry-ha@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 15:13:44 by andry-ha          #+#    #+#             */
/*   Updated: 2026/03/11 17:07:59 by andry-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "../push_swap.h"
#include "sorting.h"

/* Trouve l’élément avec le plus petit index */
static t_stack	*find_min(t_stack *stack)
{
	t_stack *min = stack;
	while (stack)
	{
		if (stack->index < min->index)
			min = stack;
		stack = stack->next;
	}
	return min;
}

/* Positionner l’élément le plus petit en haut avec rotations */
static void	move_min_top(t_stack **a, int print)
{
	t_stack *min;
	t_stack *tmp;
	int pos;

	min = find_min(*a);
	pos = 0;
	tmp = *a;
	while (tmp && tmp != min)
	{
		tmp = tmp->next;
		pos++;
	}

	int size = stack_size(*a);

	if (pos <= size / 2)
	{
		while (pos-- > 0)
			ra(a, print);
	}
	else
	{
		pos = size - pos;
		while (pos-- > 0)
			rra(a, print);
	}
}

void	sort_5(t_stack **a, t_stack **b, int print)
{
	int size = stack_size(*a);

	while (size > 3)
	{
		move_min_top(a, print);
		pb(a, b, print);
	}

	sort_3(a, print);

	while (*b)
		pa(a, b, print);
}
