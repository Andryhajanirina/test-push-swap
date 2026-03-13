/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andry-ha <andry-ha@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/08 14:50:30 by andry-ha          #+#    #+#             */
/*   Updated: 2026/03/13 17:10:17 by andry-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "../push_swap.h"
#include "parsing.h"
#include "../utils/libft/libft.h"

void parse_flags(int argc, char **argv, t_config *cfg)
{
    int i = 1;
    cfg->bench = 0;

    while (i < argc && argv[i][0] == '-')
    {
        if (ft_strncmp(argv[i], "-b", 2) == 0)
            cfg->bench = 1;
        i++;
    }
}

/* int	parse_args(int argc, char **argv, t_stack **a)
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
} */
