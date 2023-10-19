/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecorona- <ecorona-@student.42porto.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 10:44:42 by ecorona-          #+#    #+#             */
/*   Updated: 2023/10/19 17:57:41 by ecorona-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putbase_fd(char *set, long unsigned int n, int fd)
{
	unsigned int	base;
	int				nb_digits;

	nb_digits = 0;
	if (!set || !*set)
		set = "0123456789";
	base = ft_strlen(set);
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

int	ft_printc_fd(va_list argp, int fd)
{
	char	c;

	c = (char) va_arg(argp, int);
	ft_putchar_fd(c, fd);
	return (1);
}

int	ft_prints_fd(va_list argp, int fd)
{
	char	*str;

	str = va_arg(argp, char *);
	ft_putstr_fd(str, fd);
	return (ft_strlen(str));
}
