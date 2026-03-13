/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andry-ha <andry-ha@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 10:05:02 by andry-ha          #+#    #+#             */
/*   Updated: 2026/03/13 17:31:47 by andry-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	add_back(t_stack **stack, int value)
{
	t_stack	*new;
	t_stack	*last;

	new = malloc(sizeof(t_stack));
	last = *stack;
	if (!new)
		return ;
	new->value = value;
	new->next = NULL;
	if (*stack == NULL)
	{
		*stack = new;
		return ;
	}
	while (last->next)
		last = last->next;
	last->next = new;
}

int	stack_size(t_stack *stack)
{
	int	count;

	count = 0;
	while (stack)
	{
		count++;
		stack = stack->next;
	}
	return (count);
}

int	*stack_to_array(t_stack *stack, int size)
{
	int	*arr;
	int	i;

	arr = malloc(sizeof(int) * size);
	if (!arr)
		return (NULL);
	i = 0;
	while (stack)
	{
		arr[i] = stack->value;
		stack = stack->next;
		i++;
	}
	return (arr);
}

void	sort_array(int *arr, int size)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	while (i < size - 1)
	{
		j = 0;
		while (j < size - i - 1)
		{
			if (arr[j] > arr[j + 1])
			{
				tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
			j++;
		}
		i++;
	}
}

void	assign_index(t_stack *stack, int *arr, int size)
{
	int	i;

	while (stack)
	{
		i = 0;
		while (i < size)
		{
			if (stack->value == arr[i])
			{
				stack->index = i;
				break ;
			}
			i++;
		}
		stack = stack->next;
	}
}

float	compute_disorder(t_stack **stack)
{
	int		mistakes;
	int		total_pairs;
	int		i;
	int		j;
	int		size;

	mistakes = 0;
	total_pairs = 0;
	i = 0;
	size = stack_size(*stack);
	while (i < size - 1)
	{
		j = i + 1;
		while (j < size - 1)
		{
			total_pairs += 1;
			if (stack[i] > stack[j])
				mistakes += 1;
			j++;
		}
		i++;
	}
	return ((float)mistakes / (float)total_pairs);
}

int	binary_search(int *arr, int size, int x)
{
	int	low;
	int	high;
	int	mid;

	low = 0;
	high = size - 1;
	while (low <= high)
	{
		mid = low + (high - low) / 2;
		if (arr[mid] < x)
			low = mid + 1;
		else if (arr[mid] > x)
			high = mid - 1;
		else
			return (mid);
	}
	return (-1);
}

#include "../push_swap.h"

/* Trouve l’élément avec le plus petit index */
t_stack *find_min(t_stack *stack)
{
	t_stack *min = stack;
	while (stack)
	{
		if (stack->index < min->index)
			min = stack;
		stack = stack->next;
	}
	return min;
}

