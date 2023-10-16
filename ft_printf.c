/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecorona- <ecorona-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 21:27:15 by ecorona-          #+#    #+#             */
/*   Updated: 2023/10/16 11:39:27 by ecorona-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_putubase_fd(char *set, long unsigned int n, int fd)
{
	unsigned int	base;
	int				nb_digits;

	nb_digits = 0;
	if (!set || !*set)
		set = "0123456789";
	base = ft_strlen(set);
	if (n >= base)
	{
		nb_digits += ft_putubase_fd(set, n / base, fd);
		ft_putubase_fd(set, n % base, fd);
		return (nb_digits + 1);
	}
	else
	{
		ft_putchar_fd(set[n], fd);
		return (1);
	}
}

static int	ft_putbase_fd(char *set, long int n, int fd)
{
	unsigned int	base;
	int				nb_digits;

	nb_digits = 0;
	if (!set || !*set)
		set = "0123456789";
	base = ft_strlen(set);
	if (n < 0)
	{
		ft_putchar_fd('-', 1);
		n = -n;
	}
	if (n >= base)
	{
		nb_digits += ft_putbase_fd(set, n / base, fd);
		ft_putbase_fd(set, n % base, fd);
		return (nb_digits + 1);
	}
	else
	{
		ft_putchar_fd(set[n], fd);
		return (1);
	}
}

static int	ft_nputstr_fd(char *s, int fd)
{
	int		i;

	if (s)
	{
		i = 0;
		while (*s)
		{
			ft_putchar_fd(*s++, fd);
			i++;
		}
		return (i);
	}
	else
		return (0);
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
	int				nb_chars_written;

	nb_chars_written = 0;
	hex = "0123456789abcdef";
	HEX = "0123456789ABCDEF";
	va_start(ap, format);
	while (*format)
	{
		if (!ft_strncmp(format, "%c", 2))
		{
			c = (char) va_arg(ap, int);
			ft_putchar_fd(c, 1);
			nb_chars_written++;
			format++;
		}
		else if (!ft_strncmp(format, "%s", 2))
		{
			s = va_arg(ap, char *);
			nb_chars_written += ft_nputstr_fd(s, 1);
			format++;
		}
		else if (!ft_strncmp(format, "%p", 2))
		{
			p = va_arg(ap, void *);
			nb_chars_written += ft_nputstr_fd("0x", 1);
			nb_chars_written += ft_putubase_fd(hex, (unsigned long int) p, 1);
			format++;
		}
		else if (!ft_strncmp(format, "%d", 2) || !ft_strncmp(format, "%i", 2))
		{
			d = va_arg(ap, int);
			nb_chars_written += ft_putbase_fd(0, d, 1);
			format++;
		}
		else if (!ft_strncmp(format, "%u", 2))
		{
			uint = va_arg(ap, unsigned int);
			nb_chars_written += ft_putubase_fd(0, uint, 1);
			format++;
		}
		else if (!ft_strncmp(format, "%x", 2))
		{
			d = va_arg(ap, int);
			nb_chars_written += ft_putbase_fd(hex, (long int) d, 1);
			format++;
		}
		else if (!ft_strncmp(format, "%X", 2))
		{
			d = va_arg(ap, int);
			nb_chars_written += ft_putbase_fd(HEX, (long int) d, 1);
			format++;
		}
		else if (!ft_strncmp(format, "%%", 2))
		{
			ft_putchar_fd('%', 1);
			nb_chars_written++;
			format++;
		}
		else
		{
			ft_putchar_fd(*format, 1);
			nb_chars_written++;
		}
		format++;
	}
	return (nb_chars_written);
}

/*
#include <stdio.h>

int	main(void)
{
	int	x = 100;
	int	my_return;
	int	og_return;

	(void)x;
	my_return = 0;
	og_return = 0;
	my_return += ft_printf("%c\n", '1');
	og_return += printf("%c\n", '1');
	printf("mr = %i\n", my_return);
	printf("or = %i\n\n", og_return);

	my_return = 0;
	og_return = 0;
	my_return += ft_printf("%s\n", "bananinha");
	og_return += printf("%s\n", "bananinha");
	printf("mr = %i\n", my_return);
	printf("or = %i\n\n", og_return);

	my_return = 0;
	og_return = 0;
	my_return += ft_printf("%p\n", &x);
	og_return += printf("%p\n", &x);
	printf("mr = %i\n", my_return);
	printf("or = %i\n\n", og_return);

	my_return = 0;
	og_return = 0;
	my_return += ft_printf("%d\n", x);
	og_return += printf("%d\n", x);
	printf("mr = %i\n", my_return);
	printf("or = %i\n\n", og_return);

	my_return = 0;
	og_return = 0;
	my_return += ft_printf("%i\n", x);
	og_return += printf("%i\n", x);
	printf("mr = %i\n", my_return);
	printf("or = %i\n\n", og_return);

	my_return = 0;
	og_return = 0;
	my_return += ft_printf("%u\n", x);
	og_return += printf("%u\n", x);
	printf("mr = %i\n", my_return);
	printf("or = %i\n\n", og_return);

	my_return = 0;
	og_return = 0;
	my_return += ft_printf("%x\n", x);
	og_return += printf("%x\n", x);
	printf("mr = %i\n", my_return);
	printf("or = %i\n\n", og_return);

	my_return = 0;
	og_return = 0;
	my_return += ft_printf("%X\n", x);
	og_return += printf("%X\n", x);
	printf("mr = %i\n", my_return);
	printf("or = %i\n\n", og_return);

	my_return = 0;
	og_return = 0;
	my_return += ft_printf("%%\n");
	og_return += printf("%%\n");
	printf("mr = %i\n", my_return);
	printf("or = %i\n\n", og_return);

	my_return = 0;
	og_return = 0;
	my_return += ft_printf("%i, Tartaruga deu um baile\n%d, %s\n%u, %c leao se embebedou\n4, Todo mundo provocou %s provocou\n\n&x: %p, 0x(x) = %x, 0x(x)(%%X) = %X\n", 1, 2, "A bicharada toda foi", 3, 'O', "provocou", &x, x, x);
	og_return += printf("%i, Tartaruga deu um baile\n%d, %s\n%u, %c leao se embebedou\n4, Todo mundo provocou %s provocou\n\n&x: %p, 0x(x) = %x, 0x(x)(%%X) = %X\n", 1, 2, "A bicharada toda foi", 3, 'O', "provocou", &x, x, x);
	printf("mr = %i\n", my_return);
	printf("or = %i\n\n", og_return);

	my_return = 0;
	og_return = 0;
	my_return += ft_printf(" NULL %s NULL ", NULL);
	//og_return += printf(" NULL %s NULL ", NULL);
	printf("mr = %i\n", my_return);
	printf("or = %i\n\n", og_return);
}
*/
