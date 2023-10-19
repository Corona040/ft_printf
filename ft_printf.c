/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecorona- <ecorona-@student.42porto.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 17:02:24 by ecorona-          #+#    #+#             */
/*   Updated: 2023/10/19 17:57:33 by ecorona-         ###   ########.fr       */
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
	/*
	t_placeholder	placeholders[] =
	{
		{"%c", &ft_printc_fd},
		{"%s", &ft_prints_fd},
		0
	};
	*/
	t_placeholder	**escape;

	t_placeholder	c = {"%c", &ft_printc_fd};
	t_placeholder	s = {"%s", &ft_prints_fd};
	t_placeholder	*placeholders[3];
	placeholders[0] = &c;
	placeholders[1] = &s;
	placeholders[2] = 0;

	while (*format)
	{
		escape = placeholders;
		while (*escape && ft_strncmp(format, (*escape)->placeholder, 2))
			escape++;
		if (*escape)
		{
			((*escape)->f)(argp, fd);
			format++;
		}
		else
			ft_putchar_fd(*format, fd);
		format++;
	}
	return (1);
}

int	main(void)
{
	ft_printf("%canana %s", 'B', "amarela");
}
