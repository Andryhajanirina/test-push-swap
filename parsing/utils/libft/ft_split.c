/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamiandr <mamiandr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/24 13:26:45 by mamiandr          #+#    #+#             */
/*   Updated: 2026/02/09 15:07:48 by mamiandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_word(char const *s, char c)
{
	int	i;
	int	count;
	int	in_word;

	i = 0;
	count = 0;
	in_word = 0;
	while (s[i] != '\0')
	{
		if (in_word == 0 && s[i] != c)
		{
			count++;
			in_word = 1;
		}
		if (s[i] == c)
			in_word = 0;
		i++;
	}
	return (count);
}

static char	**ft_free(char **result, int i)
{
	while (i)
	{
		i--;
		free (result[i]);
	}
	free (result);
	return (NULL);
}

static void	ft_init_vars(int *i, int *end, int *start)
{
	*i = 0;
	*end = 0;
	*start = 0;
}

char	**ft_split(char const *s, char c)
{
	char	**result;
	int		i;
	int		start;
	int		end;

	if (!s)
		return (NULL);
	result = (char **) malloc (sizeof(char *) * (ft_count_word(s, c) + 1));
	if (!result)
		return (NULL);
	ft_init_vars (&i, &end, &start);
	while (i < ft_count_word(s, c))
	{
		while (s[end] == c)
			end++;
		start = end;
		while (s[end] != c && s[end] != '\0')
			end++;
		result[i] = ft_substr(s, start, end - start);
		if (!result[i])
			return (ft_free(result, i));
		i++;
	}
	result[i] = NULL;
	return (result);
}
