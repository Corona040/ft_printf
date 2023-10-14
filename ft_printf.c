/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecorona- <ecorona-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 21:27:15 by ecorona-          #+#    #+#             */
/*   Updated: 2023/10/14 23:29:21 by ecorona-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_putubase_fd(char *set, long unsigned int n, int fd)
{
	unsigned int	base;

	if (!set || !*set)
		set = "0123456789";
	base = ft_strlen(set);
	if (n > 15)
	{
		ft_putubase_fd(set, n / base, fd);
		ft_putubase_fd(set, n % base, fd);
	}
	else
		ft_putchar_fd(set[n], fd);
}

static void	ft_putbase_fd(char *set, long int n, int fd)
{
	unsigned int	base;

	if (!set || !*set)
		set = "0123456789";
	base = ft_strlen(set);
	if (n < 0)
	{
		ft_putchar_fd('-', 1);
		n = -n;
	}
	if (n > 15)
	{
		ft_putbase_fd(set, n / base, fd);
		ft_putbase_fd(set, n % base, fd);
	}
	else
		ft_putchar_fd(set[n], fd);
}

int	ft_printf(const char *format, ...)
{
	va_list			ap;
	char			c;
	char			*s;
	void			*p;
	int				d;
	unsigned int	uint;
	char			*hex;
	char			*HEX;

	hex = "0123456789abcdef";
	HEX = "0123456789ABCDEF";
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
		else if (!ft_strncmp(format, "%p", 2))
		{
			p = va_arg(ap, void *);
			ft_putstr_fd("0x", 1);
			ft_putubase_fd(hex, (unsigned long int) p, 1);
			format++;
		}
		else if (!ft_strncmp(format, "%d", 2) || !ft_strncmp(format, "%i", 2))
		{
			d = va_arg(ap, int);
			ft_putnbr_fd(d, 1);
			format++;
		}
		else if (!ft_strncmp(format, "%u", 2))
		{
			uint = va_arg(ap, unsigned int);
			ft_putubase_fd(0, uint, 1);
			format++;
		}
		else if (!ft_strncmp(format, "%x", 2))
		{
			d = va_arg(ap, int);
			ft_putbase_fd(hex, (long int) d, 1);
			format++;
		}
		else if (!ft_strncmp(format, "%X", 2))
		{
			d = va_arg(ap, int);
			ft_putbase_fd(HEX, (long int) d, 1);
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

/*
#include <stdio.h>

int	main(void)
{
	int	x = 100;

	ft_printf("%%c: %c\n%%s: %s\n%%p: %p\n%%d: %i\n%%i: %i\n", 'e', "sabedoria", &x, x, x);
	ft_printf("%%u: %u\n%%x: %x\n%%X: %X\n", -1, x, x);
	printf("\n%%c: %c\n%%s: %s\n%%p: %p\n%%d: %i\n%%i: %i\n", 'e', "sabedoria", &x, x, x);
	printf("%%u: %u\n%%x: %x\n%%X: %X\n", -1, x, x);
}
*/
