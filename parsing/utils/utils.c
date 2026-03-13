/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamiandr <mamiandr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 17:23:29 by mamiandr          #+#    #+#             */
/*   Updated: 2026/03/13 09:14:56 by mamiandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int	ft_strcmp(const char *s1, const char*s2)
{
	int	i;

	if (!s1 || !s2 || ft_strlen(s1) != ft_strlen(s2))
		return (-1);
	i = 0;
	while ((unsigned char)s1[i] && (unsigned char)s2[i])
	{
		if ((unsigned char)s1[i] != (unsigned char)s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

float	compute_disorder(t_list *stack_a)
{
	float	mistakes;
	float	total_pairs;

	if (!stack_a)
		return (-1);
	mistakes = 0;
	total_pairs = 0;
	while (stack_a)
	{
		while (stack_a->next)
		{
			total_pairs += 1;
			if (stack_a->content > stack_a->next->content)
				mistakes += 1;
		}
		stack_a = stack_a->next;
	}
	return (mistakes / total_pairs);
}

