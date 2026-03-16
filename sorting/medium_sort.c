/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andry-ha <andry-ha@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/13 13:51:31 by andry-ha          #+#    #+#             */
/*   Updated: 2026/03/16 13:45:22 by andry-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sorting.h"

static int find_max_pos(t_stack *b)
{
    int max = b->index;
    int pos = 0;
    int i = 0;

    if (!b)
		return -1;
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
    return pos;
}

static void move_max_top(t_stack **b, t_config *cfg)
{
    int pos = find_max_pos(*b);
    int size = stack_size(*b);

    if (pos <= size / 2)
        while (pos--) rb(b, cfg);
    else
    {
        pos = size - pos;
        while (pos--) rrb(b, cfg);
    }
}

int ft_sqrt_ceil(int nb)
{
    int i = 1;
    while (i * i < nb)
        i++;
    return i;
}

/* 
chunk_size = sqrt(n)
pour chaque chunk :
    parcourir A
    si index dans chunk → pb
    sinon → ra
*/
void medium_sort(t_stack **a, t_stack **b, t_config *cfg)
{
    int size;
    int chunk;
    int pushed;

    size = stack_size(*a);
    chunk = ft_sqrt_ceil(size);
    pushed = 0;
    while (*a)
    {
        if ((*a)->index <= pushed)
        {
            pb(a, b, cfg);
            rb(b, cfg);
            pushed++;
        }
        else if ((*a)->index <= pushed + chunk)
        {
            pb(a, b, cfg);
            pushed++;
        }
        else
            ra(a, cfg);
    }
    while (*b)
    {
        move_max_top(b, cfg);
        pa(a, b, cfg);
    }
}