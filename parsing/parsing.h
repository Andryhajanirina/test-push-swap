/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andry-ha <andry-ha@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 16:31:54 by andry-ha          #+#    #+#             */
/*   Updated: 2026/03/13 17:10:32 by andry-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H
# include "../push_swap.h"
# include "../utils/utils.h"

// int		parse_args(int argc, char **argv, t_stack **a);
void	parse_flags(int argc, char **argv, t_config *cfg);
// int		check_numbers(char **argv);
int		parse_numbers(int argc, char **argv, t_stack **a);
int		check_duplicates(t_stack *stack);
void	stack_init(t_stack **a, char **argv);
// int		compute_disorder();
#endif
