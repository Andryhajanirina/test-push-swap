/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andry-ha <andry-ha@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/27 09:36:16 by andry-ha          #+#    #+#             */
/*   Updated: 2026/03/09 11:37:24 by andry-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/* PUSH */
static void push(t_stack **src, t_stack **dest)
{
	t_stack	*tmp;

	if (!src || !*src)
    return;
	tmp = *src;
	*src = (*src)->next;
	tmp->next = *dest;
	*dest = tmp;
}

void pa(t_stack **a, t_stack **b, int print)
{
	push(b, a);
	if (print)
		write(1, "pa\n", 3);
}

void pb(t_stack **a, t_stack **b, int print)
{
	push(a, b);
	if (print)
		write(1, "pb\n", 3);
}
