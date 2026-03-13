/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andry-ha <andry-ha@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 16:00:22 by andry-ha          #+#    #+#             */
/*   Updated: 2026/03/13 17:32:15 by andry-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include "utils/ftprintf/ft_printf.h"

typedef struct s_stack
{
	int				value;
	int				index;
	struct s_stack	*next;
}	t_stack;

typedef struct s_config
{
    int mode;      // SIMPLE, MEDIUM, COMPLEX, ADAPTIVE
    int bench;
} t_config;
#endif