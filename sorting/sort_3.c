/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andry-ha <andry-ha@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 15:13:44 by andry-ha          #+#    #+#             */
/*   Updated: 2026/03/10 09:39:40 by andry-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void sort_3(t_stack **a, int print)
{
	int first;
	int second;
	int third;

	first = (*a)->index;
	second = (*a)->next->index;
	third = (*a)->next->next->index;

	// 1, 0, 2
	if (first > second && first < third && second < third)
		sa(a, print);
	//2, 1, 0
	else if (first > second && second > third && first > third)
	{
		sa(a, print);
		rra(a, print);
	}
	//2, 0, 1
	//3 > 1 < 2
	else if (first > second && second < third && first > third)
		ra(a, print);
	//1, 2, 0 
	else if (first < second && first > third && second > third) 
		rra(a, print);
	//0, 2, 1
	else if (first < second && second > third)
	{
		sa(a, print);
		ra(a, print);
	}      
}
