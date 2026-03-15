/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andry-ha <andry-ha@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/27 09:36:16 by andry-ha          #+#    #+#             */
/*   Updated: 2026/03/15 13:43:19 by andry-ha         ###   ########.fr       */
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

void	rra(t_stack **a, int print, int *count)
{
	reverse_rotate(a);
	if (print)
		write(1, "rra\n", 4);
	if (count)
		(*count)++;		
}

void	rrb(t_stack **b, int print, int *count)
{
	reverse_rotate(b);
	if (print)
		write(1, "rra\n", 4);
	if (count)
		(*count)++;		
}

void	rrr(t_stack **a, t_stack **b, int print, int *count)
{
	reverse_rotate(a);
	reverse_rotate(b);
	if (print)
		write(1, "rrr\n", 4);
	if (count)
		(*count)++;		
}
