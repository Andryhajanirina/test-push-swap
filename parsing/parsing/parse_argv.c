/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_argv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamiandr <mamiandr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 14:41:35 by mamiandr          #+#    #+#             */
/*   Updated: 2026/03/13 09:56:36 by mamiandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include "../header.h"

int	check_duplicate(int argc, char **argv)
{
	int	i;
	int	j;

	if (argc <= 1 || !argv)
		return (-1);
	else if (argc == 2)
		return (0);
	i = 1;
	while (i < argc)
	{
		j = i + 1;
		while (j < argc)
		{
			if (ft_strcmp(argv[i], argv[j]) == 0)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

static int is_number(char *str)
{
	int i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

int	check_flags(int argc, char **argv)
{
	int	i;
	int	flag;

	if (argc <= 2 || !argv)
		return (0);
	i = 1;
	flag = -1;
	while (i < argc)
	{
		if (argv[i][0] == '-' && !ft_isdigit(argv[i][1]))
		{	if (ft_strcmp(argv[i], "--simple") == 0)
				return (1);
			else if (ft_strcmp(argv[i], "--medium") == 0)
				return (2);
			else if (ft_strcmp(argv[i], "--complex") == 0)
				return (3);
			else if (ft_strcmp(argv[i], "--adaptative") == 0)
				return (4);
			else if (ft_strcmp(argv[i], "--bench") == 0)
				break;
			return (-1);
		}
		else if (!is_number(argv[i]))
			return (5);
		i++;
	}
	return (0);
}

int	check_bench_flag(int argc, char **argv)
{
	if (argc <= 2 || !argv)
		return (0);
	if (ft_strcmp(argv[1], "--bench") == 0)
		return (1);
	return (0);
}

//void	fill_stack(int argc, char **argv, t_list **data)
//{
//	t_list	list_tmp;
//	int		i;
//	int		temp;

//	if (argc <= 1 || !argv)
//		return ;
//	i = 1;
//	while (i < argc)
//	{
//		temp = ft_atoi(argv[i]);
//		list_tmp = ft_lstnew(temp);
//		ft_lstadd_back(data, list_tmp);
//		i++;
//	}
//}
