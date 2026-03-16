/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andry-ha <andry-ha@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 16:31:54 by andry-ha          #+#    #+#             */
/*   Updated: 2026/03/16 15:33:33 by andry-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H
# include "../push_swap.h"
# include "../utils/utils.h"

int		parse_flags(int argc, char **argv, t_config *cfg);
int		parse_numbers(int argc, char **argv, t_stack **a);
int		check_duplicates(t_stack *stack);
void	stack_init(t_stack **a, char **argv);
#endif
