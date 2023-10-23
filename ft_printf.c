/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecorona- <ecorona-@student.42porto.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 17:02:24 by ecorona-          #+#    #+#             */
/*   Updated: 2023/10/23 18:45:43 by ecorona-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	va_list argp;
	int		fd;

	va_start(argp, format);
	fd = 1;
	ft_print_fd(format, argp, fd);
	va_end(argp);
	return (1);
}

int	ft_print_fd(const char *format, va_list argp, int fd)
{
	t_placeholder	**escape;

	t_placeholder	c = {'c', &ft_printc_fd};
	t_placeholder	s = {'s', &ft_prints_fd};
	t_placeholder	p = {'p', &ft_printp_fd};
	t_placeholder	d = {'d', &ft_printi_fd};
	t_placeholder	i = {'i', &ft_printi_fd};
	/*
	t_placeholder	u = {'u', &ft_printu_fd};
	t_placeholder	x = {'x', &ft_printx_fd};
	t_placeholder	X = {'X', &ft_printX_fd};
	t_placeholder	% = {'%', &ft_print%_fd};
	*/

	t_placeholder	*placeholders[] =
	{
		&c,
		&s,
		&p,
		&d,
		&i,
		/*
		&u,
		&x,
		&X,
		&%,
		*/
		0
	};

	while (*format)
	{
		escape = placeholders;
		if (*format == '%')
		{
			format++;
			while (*escape && *format != (*escape)->placeholder)
				escape++;
			if (*escape)
				((*escape)->f)(argp, fd);
			else
				ft_putchar_fd(*(--format), fd);
		}
		else
			ft_putchar_fd(*format, fd);
		format++;
	}
	return (1);
}

#include <stdio.h>
int	main(void)
{
	char	*str = "erde";

	ft_printf("%canana %s\n%p\n%i\n%d\n", 'B', str, str, 7, -10);
	printf("%canana %s\n%p\n%i\n%d\n", 'B', str, str, 7, -10);
}
