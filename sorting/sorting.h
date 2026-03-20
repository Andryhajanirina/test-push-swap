/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andry-ha <andry-ha@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 16:31:54 by andry-ha          #+#    #+#             */
/*   Updated: 2026/03/20 09:17:31 by andry-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SORTING_H
# define SORTING_H
# include "../push_swap.h"
# include "../utils/utils.h"
# include "../operations/operations.h"

void	index_stack(t_stack *a);
void	sort_3(t_stack **a, t_config *cfg);
void	sort_5(t_stack **a, t_stack **b, t_config *cfg);
void	radix_sort(t_stack **a, t_stack **b, t_config *cfg);
void	radix_sort_2bits(t_stack **a, t_stack **b, t_config *cfg);
void	quicksort_stack(t_stack **a, t_stack **b, int size, t_config *cfg);
void	simple_sort(t_stack **a, t_stack **b, t_config *cfg);
void	medium_sort(t_stack **a, t_stack **b, t_config *cfg);
void	assign_index(t_stack *stack, int *arr, int size);

#endif
