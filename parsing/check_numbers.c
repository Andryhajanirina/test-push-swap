/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_numbers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andry-ha <andry-ha@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/08 15:09:00 by andry-ha          #+#    #+#             */
/*   Updated: 2026/03/13 15:56:42 by andry-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

// int check_numbers(char **argv)
// {
//     return (0);//Not yet implemented
// }

int parse_numbers(int argc, char **argv, t_stack **a)
{
    int i = 1;
    int num;

    while (i < argc)
    {
        // ignorer flags
        if (argv[i][0] == '-' && !ft_isdigit(argv[i][1]))
        {
            i++;
            continue;
        }

        if (!ft_atoi_safe(argv[i], &num))
            return 0; // erreur de parsing ou overflow

        add_back(a, num); // ajoute à la stack
        i++;
    }

    if (check_duplicates(*a))
        return 0;

    return 1;
}