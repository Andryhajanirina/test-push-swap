/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andry-ha <andry-ha@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 15:57:10 by andry-ha          #+#    #+#             */
/*   Updated: 2026/03/13 16:42:11 by andry-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		i;
	int		count;

	if (!str)
		return (0);
	va_start(args, str);
	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == '%' && str[i + 1])
		{
			i++;
            if (str[i] == '.')
            {
                int precision = 0;

                i++;
                while (str[i] >= '0' && str[i] <= '9')
                {
                    precision = precision * 10 + (str[i] - '0');
                    i++;
                }

                if (str[i] == 'f')
                {
                    double val = va_arg(args, double);
                    count += ft_print_float(val, precision);
                }
                else
                    count += write(1, &str[i], 1);
            }
			else
				count += handle_format(str[i], args);
		}
		else
			count += write(1, &str[i], 1);
		i++;
	}
	va_end(args);
	return (count);
}
