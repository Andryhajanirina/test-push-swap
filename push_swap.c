/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andry-ha <andry-ha@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 15:13:44 by andry-ha          #+#    #+#             */
/*   Updated: 2026/03/20 15:12:16 by andry-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "parsing/parsing.h"
#include "sorting/sorting.h"
#include "utils/utils.h"

static void	print_strategy(int fd, float disorder, t_config cfg)
{
	if (cfg.simple)
		ft_printf(fd, "[bench] strategy: Simple / O(n²)\n");
	else if (cfg.medium)
		ft_printf(fd, "[bench] strategy: Medium / O(n√n)\n");
	else if (cfg.complex)
		ft_printf(fd, "[bench] strategy: Complex / O(n log n)\n");
	else if (cfg.adaptive)
	{
		if (disorder < 0.2)
			ft_printf(fd, "[bench] strategy: Adaptive / O(n²)\n");
		else if (disorder >= 0.2 && disorder < 0.5)
			ft_printf(fd, "[bench] strategy: Adaptive / O(n√n)\n");
		else
			ft_printf(fd, "[bench] strategy: Adaptive / O(n log n)\n");
	}
	else
	{
		if (disorder < 0.2)
			ft_printf(fd, "[bench] strategy: Adaptive / O(n²)\n");
		else if (disorder >= 0.2 && disorder < 0.5)
			ft_printf(fd, "[bench] strategy: Adaptive / O(n√n)\n");
		else
			ft_printf(fd, "[bench] strategy: Adaptive / O(n log n)\n");
	}
}

static void	print_bench_stats(int fd, float disorder, t_config cfg)
{
	int	total;
	int	i;

	total = 0;
	i = -1;
	while (++i < 11)
		total += cfg.ops[i];
	if (cfg.bench)
	{
		ft_printf(fd, "[bench] disorder: %.2f%%\n", disorder * 100);
		print_strategy(fd, disorder, cfg);
		ft_printf(fd, "[bench] total_ops: %d\n", total);
		ft_printf(fd, "[bench] sa: %d sb: %d ss: %d pa: %d pb: %d\n",
			cfg.ops[SA], cfg.ops[SB], cfg.ops[SS], cfg.ops[PA], cfg.ops[PB]);
		ft_printf(fd, "[bench] ra: %d rb: %d rr: %d rra: %d rrb: %d rrr: %d\n",
			cfg.ops[RA], cfg.ops[RB], cfg.ops[RR],
			cfg.ops[RRA], cfg.ops[RRB], cfg.ops[RRR]);
	}
}

static void	choose_strategy(t_stack **a, t_stack **b, t_config *cfg)
{
	int		size;
	float	dis;

	size = stack_size(*a);
	dis = compute_disorder(a);
	if (size < 2)
		return ;
	if (cfg->simple || (cfg->adaptive && dis < 0.2) || dis < 0.2 || size <= 5)
		simple_sort(a, b, cfg);
	else if (cfg->medium || (dis >= 0.2 && dis < 0.5) || size <= 100
		|| (cfg->adaptive && dis < 0.5 && size <= 100))
		medium_sort(a, b, cfg);
	else if (cfg->complex || dis >= 0.5)
		quicksort_stack(a, b, size, cfg);
	else
		simple_sort(a, b, cfg);
}

int	main(int argc, char **argv)
{
	t_stack		*a;
	t_stack		*b;
	t_config	cfg;
	float		disorder;

	a = NULL;
	b = NULL;
	if (argc < 2)
		return (0);
	if (parse_flags(argc, argv, &cfg) == -1)
		return (write(2, "Error\n", 6), 1);
	if (!parse_numbers(argc, argv, &a))
		return (free_stack(&a), write(2, "Error\n", 6), 1);
	if (!a)
		return (0);
	index_stack(a);
	disorder = compute_disorder(&a);
	choose_strategy(&a, &b, &cfg);
	if (cfg.bench)
		print_bench_stats(2, disorder, cfg);
	return (free_stack(&a), 0);
}
