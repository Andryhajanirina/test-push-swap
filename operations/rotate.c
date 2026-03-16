/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andry-ha <andry-ha@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/27 09:36:16 by andry-ha          #+#    #+#             */
/*   Updated: 2026/03/16 13:33:25 by andry-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"

static void	rotate(t_stack **stack)
{
	t_stack	*first;
	t_stack	*last;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	first = *stack;
	*stack = first->next;
	first->next = NULL;
	last = *stack;
	while (last->next)
		last = last->next;
	last->next = first;
}

void	ra(t_stack **a, t_config *cfg)
{
	rotate(a);
	if (cfg && !cfg->bench)
		write(1, "ra\n", 3);
	if (cfg && cfg->bench)
		cfg->ops[RA]++;
}

void	rb(t_stack **b, t_config *cfg)
{
	rotate(b);
	if (cfg && !cfg->bench)
		write(1, "rb\n", 3);
	if (cfg && cfg->bench)
		cfg->ops[RB]++;
}

void	rr(t_stack **a, t_stack **b, t_config *cfg)
{
	rotate(a);
	rotate(b);
	if (cfg && !cfg->bench)
		write(1, "rr\n", 3);
	if (cfg && cfg->bench)
		cfg->ops[RR]++;
}
