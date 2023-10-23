/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecorona- <ecorona-@student.42porto.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 10:44:42 by ecorona-          #+#    #+#             */
/*   Updated: 2023/10/20 11:51:10 by ecorona-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putbase_fd(char *set, t_nbr n, int fd)
{
	t_nbr	base;
	int		nb_digits;

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

int	ft_printp_fd(va_list argp, int fd)
{
	void	*p;
	t_nbr	nbr;

	p = va_arg(argp, void *);
	nbr.p = (long unsigned int) p;
	ft_putstr_fd("0x", fd);
	return (ft_putbase_fd("0123456789abcdef", nbr, fd) + 2);
}

int	ft_printi_fd(va_list argp, int fd)
{
	int		i;
	t_nbr	nbr;

	i = va_arg(argp, int);
	nbr.i = i;
	return (ft_putbase_fd("0123456789", nbr, fd));
}
