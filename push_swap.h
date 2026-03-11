/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andry-ha <andry-ha@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 16:00:22 by andry-ha          #+#    #+#             */
/*   Updated: 2026/03/10 09:36:33 by andry-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>

typedef struct	s_stack
{
	int				value;
	int				index;
	struct s_stack *next;
}t_stack;



/* PARSING */
int		parse_args(int argc, char **argv, t_stack **a);
int		check_numbers(char **argv);
int		check_duplicates(t_stack *stack);
void	stack_init(t_stack **a, char **argv);

/* OPERATIONS */
void	sa(t_stack **a, int print);
void	sb(t_stack **b, int print);
void	ss(t_stack **a, t_stack **b, int print);

void	pa(t_stack **a, t_stack **b, int print);
void	pb(t_stack **a, t_stack **b, int print);

void	ra(t_stack **a, int print);
void	rb(t_stack **b, int print);
void	rr(t_stack **a, t_stack **b, int print);

void	rra(t_stack **a, int print);
void	rrb(t_stack **b, int print);
void	rrr(t_stack **a, t_stack **b, int print);

/* sorting */
void	index_stack(t_stack *a);
void	sort_stack(t_stack **a, t_stack **b, int print);
void	sort_3(t_stack **a, int print);
void	sort_5(t_stack **a, t_stack **b, int print);
void	radix_sort(t_stack **a, t_stack **b, int print);
/* void	buble_sort(int *arr, int length); */

/* utils */
int		stack_size(t_stack *stack);
int		*stack_to_array(t_stack *stack, int size);
void	add_back(t_stack **stack, int value);
void	sort_array(int *arr, int size);
void	assign_index(t_stack *stack, int *arr, int size);
void	free_stack(t_stack *stack);
float 	compute_disorder(t_stack **a);
#endif