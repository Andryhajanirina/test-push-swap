/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hello.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andry-ha <andry-ha@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 17:19:03 by andry-ha          #+#    #+#             */
/*   Updated: 2026/03/05 17:34:15 by andry-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

char *say_hello(char *name)
{
    char    *c_name;
    char    *tmp;
    int     i;
    int     j;

    c_name = malloc(sizeof("Hello") + sizeof(name) + 1);
    if(!c_name)
        return(NULL);
    i = 0;
    tmp = "Hello ";
    while (*tmp != '\0')
    {
        c_name[i] = *tmp;
        i++;
        tmp++;
    }
    j = 0;
    while (name[j] != '\0')
    {
        c_name[i] += name[j];
        i++;
        j++;
    }
    c_name[i] = '\0';
    return (c_name);
}