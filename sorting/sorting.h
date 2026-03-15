/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andry-ha <andry-ha@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 16:31:54 by andry-ha          #+#    #+#             */
/*   Updated: 2026/03/15 14:04:32 by andry-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SORTING_H
# define SORTING_H
# include "../push_swap.h"
# include "../utils/utils.h"
# include "../operations/operations.h"

void	index_stack(t_stack *a);
void	sort_stack(t_stack **a, t_stack **b, int print, int *count);
void	sort_3(t_stack **a, int print, int *count);
void	sort_5(t_stack **a, t_stack **b, int print, int *count);
void	radix_sort(t_stack **a, t_stack **b, int print, int *count);
void	simple_sort(t_stack **a, t_stack **b, int print, int *count);
void	medium_sort(t_stack **a, t_stack **b, int print, int *count);

#endif
