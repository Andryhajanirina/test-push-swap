/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andry-ha <andry-ha@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/08 16:19:36 by andry-ha          #+#    #+#             */
/*   Updated: 2026/03/09 13:05:57 by andry-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void index_stack(t_stack *stack)
{
    int *arr;
    int size;

    if (!stack)
		return ;
    size = stack_size(stack);
    arr = stack_to_array(stack, size);
	if (!arr)
		return ;

    sort_array(arr, size);
    assign_index(stack, arr, size);

    free(arr);
}