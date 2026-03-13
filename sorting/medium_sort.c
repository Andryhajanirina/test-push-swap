/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andry-ha <andry-ha@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/13 13:51:31 by andry-ha          #+#    #+#             */
/*   Updated: 2026/03/13 15:02:38 by andry-ha         ###   ########.fr       */
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

static void move_max_top(t_stack **b)
{
    int pos = find_max_pos(*b);
    int size = stack_size(*b);

    if (pos <= size / 2)
        while (pos--) rb(b, 1);
    else
    {
        pos = size - pos;
        while (pos--) rrb(b, 1);
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
void medium_sort(t_stack **a, t_stack **b, int print)
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
            pb(a, b, print);
            rb(b, print);
            pushed++;
        }
        else if ((*a)->index <= pushed + chunk)
        {
            pb(a, b, print);
            pushed++;
        }
        else
            ra(a, print);
    }
    while (*b)
    {
        move_max_top(b);
        pa(a, b, print);
    }
}