/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andry-ha <andry-ha@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/08 16:14:04 by andry-ha          #+#    #+#             */
/*   Updated: 2026/03/12 15:38:19 by andry-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sorting.h"

void	sort_stack(t_stack **a, t_stack **b, int print)
{
	int	size;

	size = stack_size(*a);
	if (size <= 1)
		return ;
	if (size == 2)
	{
		if ((*a)->value > (*a)->next->value)
			sa(a, print);
	}
	else if (size == 3)
	{
		ft_printf("sort_3\n");
		sort_3(a, print);
	}
	else if (size <= 5)
	{
		ft_printf("sort_5\n");
		sort_5(a, b, print);
	}
	else
	{
		ft_printf("radix_sort\n");
		radix_sort(a, b, print);
	}
}

/* POUR LE TEST */
void	print_stack(t_stack *stack)
{
	while (stack)
	{
		ft_printf("%d ", stack->value);
		stack = stack->next;
	}
	ft_printf("\n");
}

/* int	main(void)
{
	t_stack *a = NULL;
	t_stack *b = NULL;
	// int values[] = {2, 1, 3, 6, 5, 8};
	int values[] = {2, 1, 3, 6};
	int i = 0;
	int size;

	size = (sizeof(values) / sizeof(int));
	// Remplissage automatique
	while (i < size)
	{
		add_back(&a, values[i]);
		i++;
	}
	
	index_stack(a);
	printf("Before:\n");
	print_stack(a);

	sort_stack(&a, &b, 0);

	printf("After:\n");
	print_stack(a);
	return (0);
} */
