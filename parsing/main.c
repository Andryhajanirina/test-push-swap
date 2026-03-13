/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamiandr <mamiandr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 14:44:45 by mamiandr          #+#    #+#             */
/*   Updated: 2026/03/13 09:52:06 by mamiandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stdio.h>

int	main(int argc, char *argv[])
{
	int	flag;
	int	bench_mode;

	if (argc == 1)
	{
		ft_printf("tsy misy arguments mihintsy an\n");
		return (1);
	}
	flag = check_flags(argc, argv);
	bench_mode = check_bench_flag(argc, argv);

	if (flag == -1)
	{
		ft_printf("Misy flag illegal\n");
		return(1);
	}
	else if (flag == 5)
	{
		ft_printf("Misy argument tsy poins\n");
		return(1);
	}
	if (check_duplicate(argc, argv) == 1)
	{
		ft_printf("tena misy doublon an\n");
		return (1);
	}
	else
	{
		if (bench_mode == 1)
			ft_printf("bench mode activate\n");
		ft_printf("%d: Le programme suit son cours...\n", flag);
		//push_swap(argc, argv, flag, bench_mode);
	}
	return (0);
}
