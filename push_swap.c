/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andry-ha <andry-ha@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 15:13:44 by andry-ha          #+#    #+#             */
/*   Updated: 2026/03/16 13:42:56 by andry-ha         ###   ########.fr       */
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

/* static void init_ops(t_config *cfg)
{
	cfg->ops[PA] = 0;
	cfg->ops[PB] = 0;
	cfg->ops[SA] = 0;
	cfg->ops[SB] = 0;
	cfg->ops[SS] = 0;
	cfg->ops[RA] = 0;
	cfg->ops[RB] = 0;
	cfg->ops[RR] = 0;
	cfg->ops[RRA] = 0;
	cfg->ops[RRB] = 0;
	cfg->ops[RRR] = 0;
} */
/**
 * The optional benchmark mode (--bench) must display, after sorting:
 * The computed disorder (% with two decimals).
 * The name of the strategy used and its theoretical complexity class.
 * The total number of operations.
 * The count of each operation type (sa, sb, ss, pa, pb, ra, rb, rr, rra, rrb,
rrr).
 */
/* static void	print_stats(int count, float disorder, t_config cfg)
{
	if (cfg.bench)
	{
		ft_printf("\n[bench] disorder: %.2f%%\n", disorder * 100);
		if (cfg.simple)
			ft_printf("[bench] strategy: Simple / O(n\u00B2)\n");
		else if (cfg.medium)
			ft_printf("[bench] strategy: Medium / O(n\u221An)\n");
		else if (cfg.complex)
			ft_printf("[bench] strategy: Complex / O(n log n)\n");
		else if (cfg.adaptive)
		{
			if (disorder < 0.2)
				ft_printf("[bench] strategy: Adaptive / O(n\u00B2)\n");
			else if (0.2 <= disorder <= 0.5)
				ft_printf("[bench] strategy: Adaptive / O(n\u221An)\n");
			else
				ft_printf("[bench] strategy: Adaptive / O(n log n)\n");
		}
	}
} */

static void	print_bench_stats(float disorder, t_config cfg)
{
	int	total;
	int	i;

	total = 0;
	i = -1;
	while (++i < 11)
		total += cfg.ops[i];

	if (cfg.bench)
	{
		ft_printf("[bench] disorder: %.2f%%\n", disorder * 100);
		if (cfg.simple)
			ft_printf("[bench] strategy: Simple / O(n\u00B2)\n");
		else if (cfg.medium)
			ft_printf("[bench] strategy: Medium / O(n\u221An)\n");
		else if (cfg.complex)
			ft_printf("[bench] strategy: Complex / O(n log n)\n");
		else if (cfg.adaptive)
		{
			if (disorder < 0.2)
				ft_printf("[bench] strategy: Adaptive / O(n\u00B2)\n");
			else if (0.2 <= disorder <= 0.5)
				ft_printf("[bench] strategy: Adaptive / O(n\u221An)\n");
			else
				ft_printf("[bench] strategy: Adaptive / O(n log n)\n");
		}
		ft_printf("[bench] total_ops: %d\n", total);
		ft_printf("[bench] sa: %d sb: %d ss: %d pa: %d pb: %d\n",
			cfg.ops[SA], cfg.ops[SB], cfg.ops[SS], cfg.ops[PA], cfg.ops[PB]);
		ft_printf("[bench] ra: %d rb: %d rr: %d rra: %d rrb: %d rrr: %d\n",
			cfg.ops[RA], cfg.ops[RB], cfg.ops[RR], 
			cfg.ops[RRA], cfg.ops[RRB], cfg.ops[RRR]);
	}
}


// static void	choose_strategy(t_stack **a, t_stack **b, t_config cfg, int print, t_config *cfg)
static void	choose_strategy(t_stack **a, t_stack **b, t_config *cfg)
{
	int	size;
	float	disorder;

	disorder = compute_disorder(a);
	size = stack_size(*a);
	if (cfg->complex)
		radix_sort(a, b, cfg);
	else if (cfg->medium)
		medium_sort(a, b, cfg);
	else if (cfg->simple)
		simple_sort(a, b, cfg);
	else if (cfg->adaptive)
	{
		if (disorder < 0.2)
			simple_sort(a, b, cfg);
		else if (0.2 <= disorder <= 0.5)
			medium_sort(a, b, cfg);
		else
			radix_sort(a, b, cfg);
	}
	else
		simple_sort(a, b, cfg);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	t_config cfg;
	int		ops	;
	float	disorder;

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

	disorder = compute_disorder(&a);
	
	choose_strategy(&a, &b, &cfg);
	
	if (cfg.bench)
		print_bench_stats(disorder, cfg);
	free_stack(&a);
	return (0);
}
