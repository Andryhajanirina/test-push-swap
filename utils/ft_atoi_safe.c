/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_safe.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andry-ha <andry-ha@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/13 15:52:06 by andry-ha          #+#    #+#             */
/*   Updated: 2026/03/13 15:52:09 by andry-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int ft_atoi_safe(const char *str, int *out)
{
    long result = 0;
    int sign = 1;
    int i = 0;

    if (str[i] == '+' || str[i] == '-')
    {
        if (str[i] == '-')
            sign = -1;
        i++;
    }

    if (!str[i])
        return 0; // chaîne vide après signe → erreur

    while (str[i])
    {
        if (str[i] < '0' || str[i] > '9')
            return 0; // caractère non-numérique → erreur
        result = result * 10 + (str[i] - '0');
        // vérification overflow int sur 32 bits
        if (result * sign > 2147483647 || result * sign < -2147483648)
            return 0;
        i++;
    }

    *out = (int)(result * sign);
    return 1; // ok
}