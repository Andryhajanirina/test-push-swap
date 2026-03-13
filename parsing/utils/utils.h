/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamiandr <mamiandr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 16:12:37 by mamiandr          #+#    #+#             */
/*   Updated: 2026/03/11 17:43:17 by mamiandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "./libft/libft.h"
# include "./ft_printf/ft_printf.h"

int		ft_strcmp(const char *s1, const char*s2);
float	compute_disorder(t_list *stack_a);

#endif
