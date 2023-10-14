/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecorona- <ecorona-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 21:27:15 by ecorona-          #+#    #+#             */
/*   Updated: 2023/10/14 21:53:03 by ecorona-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdarg.h>

int ft_printf(const char *format, ...)
{
	va_list ap;
	char	c;
	char	*s;
	int		d;

	va_start(ap, format);
	while (*format)
	{
		if (!ft_strncmp(format, "%c", 2))
		{
			c = (char) va_arg(ap, int);
			ft_putchar_fd(c, 1);
			format++;
		}
		else if (!ft_strncmp(format, "%s", 2))
		{
			s = va_arg(ap, char *);
			ft_putstr_fd(s, 1);
			format++;
		}
		else if (!ft_strncmp(format, "%i", 2))
		{
			d = va_arg(ap, int);
			ft_putnbr_fd(d, 1);
			format++;
		}
		else if (!ft_strncmp(format, "%%", 2))
		{
			ft_putchar_fd('%', 1);
			format++;
		}
		else
			ft_putchar_fd(*format, 1);
		format++;
	}
	return (1);
}

int	main(void)
{
	ft_printf("%s%c%i%%", "sabedoria", ' ', 56);
}
