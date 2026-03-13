/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamiandr <mamiandr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/24 10:50:39 by mamiandr          #+#    #+#             */
/*   Updated: 2026/02/09 15:08:09 by mamiandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	unsigned int	size;
	char			*result;

	size = ft_strlen(s1) + ft_strlen(s2) + 1;
	result = (char *) malloc (sizeof(char) * size);
	if (!result)
		return (NULL);
	result[0] = '\0';
	ft_strlcat(result, s1, size);
	ft_strlcat(result, s2, size);
	result[size - 1] = '\0';
	return (result);
}
