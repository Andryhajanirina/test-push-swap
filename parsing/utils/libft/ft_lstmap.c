/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamiandr <mamiandr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/31 11:39:27 by mamiandr          #+#    #+#             */
/*   Updated: 2026/02/11 00:31:57 by mamiandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*result;
	t_list	*nelm;
	void	*content;

	if (!lst || !f || !del)
		return (NULL);
	result = NULL;
	while (lst)
	{
		content = f(lst->content);
		nelm = ft_lstnew(content);
		if (!nelm)
		{
			del(content);
			ft_lstclear(&result, del);
			return (NULL);
		}
		ft_lstadd_back(&result, nelm);
		lst = lst->next;
	}
	return (result);
}
