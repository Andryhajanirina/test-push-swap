/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andry-ha <andry-ha@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 16:05:50 by andry-ha          #+#    #+#             */
/*   Updated: 2026/03/13 17:31:35 by andry-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

// int     free_stack(t_stack **stack)
// {

// }
void free_stack(t_stack **stack)
{
	t_stack	*tmp;

	while (*stack)
	{
		tmp = *stack;
		*stack = (*stack)->next;
		free(tmp);
	}
	*stack = NULL;
}
