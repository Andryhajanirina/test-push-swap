/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamiandr <mamiandr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/24 09:45:36 by mamiandr          #+#    #+#             */
/*   Updated: 2026/02/09 15:08:56 by mamiandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	nbr;
	char	*str;

	nbr = ft_strlen(s);
	if (len == 0)
		return (ft_strdup("\0"));
	else if (start >= nbr)
		return (ft_strdup(""));
	else if (!len || (len > nbr - start))
		nbr = nbr - start;
	else
		nbr = len;
	str = (char *) malloc (sizeof(char) * (nbr + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (i < nbr && s[start])
		str[i++] = s[start++];
	str[i] = '\0';
	return (str);
}
