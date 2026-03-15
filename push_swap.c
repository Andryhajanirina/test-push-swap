/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andry-ha <andry-ha@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 15:13:44 by andry-ha          #+#    #+#             */
/*   Updated: 2026/03/15 15:56:41 by andry-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "parsing/parsing.h"
#include "sorting/sorting.h"
#include "utils/utils.h"


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

static void	print_stats(int count, t_config cfg)
{
	if (cfg.bench)
	{
		ft_printf("\n--- Statistics ---\n");
		ft_printf("Total operations: %d\n", count);
		if (cfg.simple)
			ft_printf("Strategy: Simple Sort\n");
		else if (cfg.medium)
			ft_printf("Strategy: Medium Sort\n");
		else if (cfg.complex)
			ft_printf("Strategy: Radix Sort\n");
		ft_printf("------------------\n");
	}
}


static void	choose_strategy(t_stack **a, t_stack **b, t_config cfg, int print, int *count)
{
	int	size;
	float	disorder;

	disorder = compute_disorder(a);
	size = stack_size(*a);
	if (cfg.complex)
		radix_sort(a, b, print, count);
	else if (cfg.medium)
		medium_sort(a, b, print, count);
	else if (cfg.simple)
		simple_sort(a, b, print, count);
	else if (cfg.adaptive)
	{
/* 		if (size <= 5)
			simple_sort(a, b, print, count);
		else if (size <= 100)
			medium_sort(a, b, print, count);
		else
			radix_sort(a, b, print, count); */
		if (disorder < 0.2)
{			ft_printf("Simple | disorder = %.2f :\n", disorder);
			simple_sort(a, b, print, count);}
		else if (0.2 <= disorder <= 0.5)
{			ft_printf("Medium | disorder = %.2f :\n", disorder);
			medium_sort(a, b, print, count);}
		else
{			ft_printf("Complex | disorder = %.2f :\n", disorder);
			radix_sort(a, b, print, count);}
	}
	else
		simple_sort(a, b, print, count);
}

int main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	t_config cfg;
	int		ops	;

	a = NULL;
	b = NULL;
	ops = 0;
	if (argc < 2)
	{
		ft_printf("Error\n");
		return (-1);
	}

	if (parse_flags(argc, argv, &cfg) == -1)
	{
		return (write(2, "Error\n", 6), 1);
	}
	if (!parse_numbers(argc, argv, &a))
	{
		free_stack(&a);
		return (write(2, "Error\n", 6), 1);
	}
	index_stack(a);

	// Avant :
	ft_printf("Avant :\n");
	print_stack(a);

	choose_strategy(&a, &b, cfg, 1, &ops);

	// Apres :
	ft_printf("Apres :\n");
	print_stack(a);

	if (cfg.bench)
		print_stats(ops, cfg);
	free_stack(&a);
	return (0);
}