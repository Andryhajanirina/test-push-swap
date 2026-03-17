/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andry-ha <andry-ha@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/27 09:36:16 by andry-ha          #+#    #+#             */
/*   Updated: 2026/03/17 17:40:15 by andry-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"

/* REVERSE AND ROTATE */
static void	reverse_rotate(t_stack **stack)
{
	t_stack	*prev;
	t_stack	*last;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	prev = NULL;
	last = *stack;
	while (last->next)
	{
		prev = last;
		last = last->next;
	}
	prev->next = NULL;
	last->next = *stack;
	*stack = last;
}

void	rra(t_stack **a, t_config *cfg)
{
	reverse_rotate(a);
	if (cfg && cfg->bench == 0)
		write(1, "rra\n", 4);
	if (cfg && cfg->bench == 1)
		cfg->ops[RRA]++;
}

void	rrb(t_stack **b, t_config *cfg)
{
	reverse_rotate(b);
	if (cfg && cfg->bench == 0)
		write(1, "rrb\n", 4);
	if (cfg && cfg->bench == 1)
		cfg->ops[RRB]++;
}

void	rrr(t_stack **a, t_stack **b, t_config *cfg)
{
	reverse_rotate(a);
	reverse_rotate(b);
	if (cfg && cfg->bench == 0)
		write(1, "rrr\n", 4);
	if (cfg && cfg->bench == 1)
		cfg->ops[RRR]++;
}
