/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamiandr <mamiandr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 11:30:44 by mamiandr          #+#    #+#             */
/*   Updated: 2026/02/09 18:20:43 by mamiandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count(int n)
{
	int	i;

	i = 0;
	if (n < 0)
	{
		i++;
		n = -n;
	}
	else if (n >= 0 && n <= 9)
	{
		i = 1;
		return (i);
	}
	while (n != 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char	*ft_fill(int *i, long *t, char *result)
{
	if ((*t) >= 0 && (*t) <= 9)
	{
		result[0] = (*t) + '0';
		return (result);
	}
	if ((*t) < 0)
	{
		result[0] = '-';
		(*t) *= -1;
	}
	(*i)--;
	while ((*t) != 0)
	{
		result[(*i)--] = (((*t) % 10) + '0');
		(*t) /= 10;
	}
	return (result);
}

char	*ft_itoa(int n)
{
	char	*result;
	int		i;
	long	t;

	t = n;
	i = ft_count(t);
	result = (char *) malloc (sizeof(char) * (i + 1));
	if (!result)
		return (NULL);
	result[i] = '\0';
	return (ft_fill(&i, &t, result));
}
