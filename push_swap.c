/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andry-ha <andry-ha@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 15:13:44 by andry-ha          #+#    #+#             */
/*   Updated: 2026/03/12 16:54:01 by andry-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "parsing/parsing.h"
#include "sorting/sorting.h"
#include "utils/utils.h"

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	if (argc < 2)
	{
		ft_printf("Argument < 2");
		return (0);
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
}
