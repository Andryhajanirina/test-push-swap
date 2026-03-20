/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andry-ha <andry-ha@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/08 14:50:30 by andry-ha          #+#    #+#             */
/*   Updated: 2026/03/20 14:48:00 by andry-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "../push_swap.h"
#include "parsing.h"
#include "../utils/libft/libft.h"

static void	init_config(t_config *cfg)
{
	int	i;

	cfg->simple = 0;
	cfg->medium = 0;
	cfg->complex = 0;
	cfg->adaptive = 0;
	cfg->bench = 0;
	i = 0;
	while (i < 11)
		cfg->ops[i++] = 0;
}

static int	set_flag(char *arg, t_config *cfg)
{
	if (!ft_strncmp(arg, "--simple", 8) && arg[8] == '\0')
		return (cfg->simple = 1);
	if (!ft_strncmp(arg, "--medium", 8) && arg[8] == '\0')
		return (cfg->medium = 1);
	if (!ft_strncmp(arg, "--complex", 9) && arg[9] == '\0')
		return (cfg->complex = 1);
	if (!ft_strncmp(arg, "--adaptive", 10) && arg[10] == '\0')
		return (cfg->adaptive = 1);
	if (!ft_strncmp(arg, "--bench", 7) && arg[7] == '\0')
		return (cfg->bench = 1);
	return (0);
}

int	parse_flags(int argc, char **argv, t_config *cfg)
{
	int	i;

	i = 1;
	init_config(cfg);
	while (i < argc)
	{
		if (argv[i][0] == '-' && (!ft_isdigit(argv[i][1])))
		{
			if (!set_flag(argv[i], cfg))
				return (-1);
		}
		i++;
	}
	return (1);
}
