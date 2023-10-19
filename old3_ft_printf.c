/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecorona- <ecorona-@student.42porto.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 10:24:47 by ecorona-          #+#    #+#             */
/*   Updated: 2023/10/19 17:01:49 by ecorona-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

typedef struct s_placeholders
{
	char	*placeholder;
	int		(*f)();
}	t_placeholders;

int	ft_printf(const char *format, ...)
{
	va_list	arg_p;

	va_start(arg_p, format);
	//check format
	//print format
	va_end(arg_p);
}

int	ft_putfmt_fd(const char *format, va_list arg_p, int fd)
{
	t_placeholders placeholders[] =
	{
		{"%c", &ft_putchar_fd},
		{"%s", &ft_putstr_fd},
		{"%p", &ft_putbase_fd},
		{"%d", &ft_putbase_fd},
		{"%i", &ft_putbase_fd},
		{"%u", &ft_putbase_fd},
		{"%x", &ft_putbase_fd},
		{"%X", &ft_putbase_fd},
		{"%%", &ft_putchar_fd},
		0
	};
	t_placeholders *escape;

	while (*format)
	{
		escape = placeholders;
		while (*escape && strncmp(format, escape->placeholder, 2))
			escape++;
		if (escape)
		{
			format++;
			call_put(escape, arg_p);
		}
		else
			ft_putchar_fd(*format);
		format++;
	}
}
