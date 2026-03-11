/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andry-ha <andry-ha@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/08 14:50:30 by andry-ha          #+#    #+#             */
/*   Updated: 2026/03/11 16:58:50 by andry-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "../push_swap.h"
#include "parsing.h"
#include "../libft/libft.h"

int	parse_args(int argc, char **argv, t_stack **a)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		add_back(a, ft_atoi(argv[i]));
		i++;
	}
	if (check_duplicates(*a))
		return (0);
	return (1);
}