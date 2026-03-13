/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andry-ha <andry-ha@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 15:13:44 by andry-ha          #+#    #+#             */
/*   Updated: 2026/03/13 17:33:38 by andry-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "parsing/parsing.h"
#include "sorting/sorting.h"
#include "utils/utils.h"

/* int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	if (argc < 2)
	{
		ft_printf("Auccun argument trouvee");
		return (-1);
	}
	if (!parse_args(argc, argv, &a))
	{
		ft_printf("Impossible de parser");
		return (-1);
	}
	index_stack(a);
	sort_stack(&a, &b, 1);
	// free_stack(a);
	return (0);
} */

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

static void choose_strategy(t_stack **a, t_stack **b, t_config cfg, int print)
{
	(void)cfg;
	int size = stack_size(*a);

	if (size <= 5)
		simple_sort(a, b, print);       // tri simple pour petites piles
	else if (size <= 100)
		medium_sort(a, b, print);       // tri moyen avec chunks
	else
		radix_sort(a, b, print);        // tri complexe O(n log n)
}

#include <time.h>

static void	print_bench(void)
{
	clock_t end = clock();
	ft_printf("Execution time: %.2f s\n", (double)end / CLOCKS_PER_SEC);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	t_config cfg;

	a = NULL;
	b = NULL;
	cfg.bench = 0;

	if (argc < 2)
	{
		ft_printf("Aucun argument trouvee\n");
		return (-1);
	}
	parse_flags(argc, argv, &cfg);// parse options type -b pour bench
	if (!parse_numbers(argc, argv, &a))
	{
		ft_printf("Impossible de parser\n");
		return (-1);
	}
	index_stack(a);

	// Avant :
	ft_printf("Avant :\n");
	print_stack(a);

	choose_strategy(&a, &b, cfg, 0);

	// Apres :
	ft_printf("Avant :\n");
	print_stack(a);

	if (cfg.bench)
		print_bench();
	free_stack(&a);
	return (0);
}
