/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamiandr <mamiandr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 11:42:06 by mamiandr          #+#    #+#             */
/*   Updated: 2026/02/09 15:07:07 by mamiandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned int		i;
	unsigned const char	*str;
	unsigned char		car;

	i = 0;
	car = (unsigned char)c;
	str = (unsigned const char *)s;
	while (i < n)
	{
		if (str[i] == car)
			return ((void *)&str[i]);
		i++;
	}
	return (0);
}
