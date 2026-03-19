/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andry-ha <andry-ha@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 13:11:17 by andry-ha          #+#    #+#             */
/*   Updated: 2026/03/19 17:28:25 by andry-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sorting.h"

static void	small_sort_n(t_stack **a, t_config *cfg, int size)
{
	if (size == 3)
		sort_3(a, cfg);
	else
	{
		if ((*a)->index > (*a)->next->index)
			sa(a, cfg);
	}
}

static int	get_pivot(t_stack *stack, int size)
{
	int		min;
	int		max;
	int		i;
	t_stack	*tmp;

	if (!stack)
		return (0);
	tmp = stack;
	min = tmp->index;
	max = tmp->index;
	i = 0;
	while (i++ < size && tmp)
	{
		if (tmp->index < min)
			min = tmp->index;
		if (tmp->index > max)
			max = tmp->index;
		tmp = tmp->next;
	}
	return ((min + max) / 2);
}

/* void	quicksort_stack(t_stack **a, t_stack **b, int size, t_config *cfg)
{
	int	pivot;
	int	pushed;
	int	rotated;
	int	count;

	if (size == 3) // Condition d'arrêt pour les petites partitions
	{
		sort_3(a, cfg);
		return ; 
	}

	if (size == 2) // Condition d'arrêt pour les petites partitions
	{
		if ((*a)->index > (*a)->next->index)
			sa(a, cfg);
		return;
	}

	pivot = get_pivot(*a, size);
	pushed = 0;
	rotated = 0;
	count = size;
	while (count--)
	{
		if ((*a)->index < pivot)
		{
			pb(a, b, cfg);
			pushed++;
		}
		else
		{
			ra(a, cfg);
			rotated++;
		}
	}
	int i = rotated;
	while (i--)
		rra(a, cfg);

	// On trie récursivement la partie restée dans A (les grands)
	quicksort_stack(a, b, size - pushed, cfg);
	
	// On trie la partie envoyée dans B (les petits) et on les remonte
	while (pushed--)
		pa(a, b, cfg);
} */

void	quicksort_stack(t_stack **a, t_stack **b, int size, t_config *cfg)
{
	int	pivot;
	int	pushed;
	int	rotated;

	if (size <= 3)
		return (small_sort_n(a, cfg, size));
	pivot = get_pivot(*a, size);
	pushed = 0;
	rotated = 0;
	while (pushed + rotated < size)
	{
		if ((*a)->index < pivot && ++pushed)
			pb(a, b, cfg);
		else if (++rotated)
			ra(a, cfg);
	}
	while (rotated--)
		rra(a, cfg);
	quicksort_stack(a, b, size - pushed, cfg);
	while (pushed--)
		pa(a, b, cfg);
}
