/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecorona- <ecorona-@student.42porto.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 10:24:47 by ecorona-          #+#    #+#             */
/*   Updated: 2023/10/17 10:57:54 by ecorona-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	int		fd;
	va_list	ap;
	char	*types;

	fd = 1;
	types = "cspdiuxX%";
	va_start(ap, format);
	while (*format)
	{
		if (*format == '%')
		{
			while (*(types + i) && *(types + i) != format)
			{
				i++;
			}
		}
		ft_putchar_fd(*format++, fd);
	}
}

int	main(void)
{
	t_data	data;
	t_flist	flist;

	data.i = 100;
	flist.d = data;
	flist.f = &ft_putnbr_fd;
	flist.f((flist.d).i, 1);
}
