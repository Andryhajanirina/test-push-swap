/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamiandr <mamiandr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 14:31:44 by mamiandr          #+#    #+#             */
/*   Updated: 2026/02/09 15:08:06 by mamiandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	int	i;
	int	k;

	if (!s || !f)
		return ;
	i = ft_strlen(s);
	k = 0;
	while (k < i)
	{
		f(k, &s[k]);
		k++;
	}
}
