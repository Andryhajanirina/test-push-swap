/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamiandr <mamiandr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/24 11:16:03 by mamiandr          #+#    #+#             */
/*   Updated: 2026/02/09 15:08:46 by mamiandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char		*result;
	size_t		start;
	size_t		end;

	if (!s1)
		return (NULL);
	start = 0;
	end = ft_strlen(s1);
	while (ft_strchr(set, s1[start]))
		start ++;
	while (ft_strchr(set, s1[end - 1]))
		end--;
	result = ft_substr(s1, start, end - start);
	return (result);
}
