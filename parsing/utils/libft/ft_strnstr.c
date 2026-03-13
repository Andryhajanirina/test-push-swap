/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamiandr <mamiandr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 11:33:13 by mamiandr          #+#    #+#             */
/*   Updated: 2026/02/09 15:08:38 by mamiandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr( const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	k;

	if (little[0] == '\0')
		return ((char *)big);
	i = 0;
	while (i < len && len != 0 && big[i] != '\0')
	{
		k = 0;
		while ((i + k < len) && big[i + k] == little[k] && little[k] != '\0')
			k++;
		if (little[k] == '\0')
			return ((char *)&big[i]);
		i++;
	}
	return (NULL);
}
