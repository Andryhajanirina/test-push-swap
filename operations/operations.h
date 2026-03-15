/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andry-ha <andry-ha@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 16:31:54 by andry-ha          #+#    #+#             */
/*   Updated: 2026/03/15 13:41:56 by andry-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPERATIONS_H
# define OPERATIONS_H
# include "../push_swap.h"

void	sa(t_stack **a, int print, int *count);
void	sb(t_stack **b, int print, int *count);
void	ss(t_stack **a, t_stack **b, int print, int *count);

void	pa(t_stack **a, t_stack **b, int print, int *count);
void	pb(t_stack **a, t_stack **b, int print, int *count);

void	ra(t_stack **a, int print, int *count);
void	rb(t_stack **b, int print, int *count);
void	rr(t_stack **a, t_stack **b, int print, int *count);

void	rra(t_stack **a, int print, int *count);
void	rrb(t_stack **b, int print, int *count);
void	rrr(t_stack **a, t_stack **b, int print, int *count);
#endif
