/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andry-ha <andry-ha@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/01 15:00:57 by andry-ha          #+#    #+#             */
/*   Updated: 2026/04/01 16:16:35 by andry-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ALGO_H
# define ALGO_H
# include "../sorting/sorting.h"
# define COST_A 0
# define COST_B 1
# define COST_TOTAL 2
# define BEST_A 0
# define BEST_B 1
# define BEST_TOTAL 2

int		find_min_pos(t_stack *a);
int		target_pos(t_stack *a, int idx);
int		calc_cost(int size, int pos);
void	best_move(t_stack **a, t_stack **b, t_config *cfg);
#endif