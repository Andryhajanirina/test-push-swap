/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andry-ha <andry-ha@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 16:31:54 by andry-ha          #+#    #+#             */
/*   Updated: 2026/03/13 17:31:56 by andry-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H
# include "../push_swap.h"

void	add_back(t_stack **stack, int value);
int		stack_size(t_stack *stack);
int		*stack_to_array(t_stack *stack, int size);
void	sort_array(int *arr, int size);
void	assign_index(t_stack *stack, int *arr, int size);
float	compute_disorder(t_stack **stack);
int		binary_search(int *arr, int size, int x);
// int	free_stack(t_stack **stack);
void	free_stack(t_stack **stack);
int     ft_atoi_safe(const char *str, int *out);
t_stack *find_min(t_stack *stack);

#endif
