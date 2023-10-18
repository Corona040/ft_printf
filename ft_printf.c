/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecorona- <ecorona-@student.42porto.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 10:24:47 by ecorona-          #+#    #+#             */
/*   Updated: 2023/10/18 12:32:12 by ecorona-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	get_type(const char **f)
{
	if (f && *f)
	{
		if (**f == '%')
		{
			(*f)++;
			if (**f == 'c' || **f == 'd' || **f == 'i'
					|| **f == 'u' || **f == 'x' || **f == 'X')
			{
				(*f)++;
				return (1);
			}
			else if (**f == 's' || **f == 'p')
			{
				(*f)++;
				return (2);
			}
			else
				return (-2);
		}
		else
		{
			(*f)++;
			return (0);
		}
	}
	else
		return (-1);
}


int	ft_printf(const char *format, ...)
{
	int		fd;
	t_data	data;
	va_list	ap;

	fd = 1;
	va_start(ap, format);
	while (*format)
	{
		if (get_type(&format) == 1)
			data.u = va_arg(ap, unsigned int);
		else if (get_type(&format) == 2)
			data.lu = va_arg(ap, unsigned long int);
	}
	return (0);
}

int	main(void)
{
	t_data	data;

	data.u = 100;
}
