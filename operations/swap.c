/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andry-ha <andry-ha@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/27 09:36:16 by andry-ha          #+#    #+#             */
/*   Updated: 2026/03/17 17:38:46 by andry-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"

static void	swap(t_stack **stack)
{
	t_stack	*first;
	t_stack	*second;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	first = *stack;
	second = first->next;
	first->next = second->next;
	second->next = first;
	*stack = second;
}

void	sa(t_stack **a, t_config *cfg)
{
	swap(a);
	if (cfg && cfg->bench == 0)
		write(1, "sa\n", 3);
	if (cfg && cfg->bench == 1)
		cfg->ops[SA]++;
}

void	sb(t_stack **b, t_config *cfg)
{
	swap(b);
	if (cfg && cfg->bench == 0)
		write(1, "sb\n", 3);
	if (cfg && cfg->bench == 1)
		cfg->ops[SB]++;
}

void	ss(t_stack **a, t_stack **b, t_config *cfg)
{
	swap(a);
	swap(b);
	if (cfg && cfg->bench == 0)
		write(1, "ss\n", 3);
	if (cfg && cfg->bench == 1)
		cfg->ops[SS]++;
}
