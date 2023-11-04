/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecorona- <ecorona-@student.42porto.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 10:44:42 by ecorona-          #+#    #+#             */
/*   Updated: 2023/11/03 11:00:15 by ecorona-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_nbrlen(int n)
{
	size_t	i;

	i = 1;
	if (n < 0)
		i++;
	while (n / 10 != 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

size_t	ft_unbrlen(unsigned int n)
{
	size_t	i;

	i = 1;
	while (n / 10 != 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

size_t	ft_hexlen(unsigned int n)
{
	size_t	i;

	i = 1;
	while (n / 16 != 0)
	{
		n /= 16;
		i++;
	}
	return (i);
}

size_t	ft_plen(unsigned long int n)
{
	size_t	i;

	i = 1;
	while (n / 16 != 0)
	{
		n /= 16;
		i++;
	}
	return (i);
}

void    ft_putunbr_fd(unsigned int n, int fd)
{
    if (n > 9)
    {
        ft_putnbr_fd(n / 10, fd);
        ft_putnbr_fd(n % 10, fd);
    }
    else
        ft_putchar_fd(n + '0', fd);
}

int	ft_puthex_fd(int upper, unsigned int n, int fd)
{
	unsigned int	base;
	char			*set;

	set = "0123456789abcdef";
	if (upper)
		set = "0123456789ABCDEF";
	base = (unsigned int) ft_strlen(set);
	if (n >= base)
	{
		ft_puthex_fd(upper, n / base, fd);
		ft_puthex_fd(upper, n % base, fd);
	}
	else
		ft_putchar_fd(set[n], fd);
	return ((int) ft_hexlen(n));
}

int	ft_putp_fd(unsigned long int n, int fd)
{
	unsigned long int	base;
	char				*set;

	set = "0123456789abcdef";
	base = (unsigned long int) ft_strlen(set);
	if (n >= base)
	{
		ft_putp_fd(n / base, fd);
		ft_putp_fd(n % base, fd);
	}
	else
		ft_putchar_fd(set[n], fd);
	return ((int) ft_plen(n) + 2);
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
	return ((int) ft_strlen(str));
}

int	ft_printp_fd(va_list argp, int fd)
{
	void				*p;
	long unsigned int	nbr;

	p = va_arg(argp, void *);
	nbr = (long unsigned int) p;
	if (nbr == 0)
	{
		ft_putstr_fd("(nil)", fd);
		return ((int) ft_strlen("(nil)"));
	}
	ft_putstr_fd("0x", fd);
	ft_putp_fd(nbr, fd);
	return ((int) ft_plen(nbr) + 2);
}

int	ft_printi_fd(va_list argp, int fd)
{
	int	nbr;

	nbr = va_arg(argp, int);
	ft_putnbr_fd(nbr, fd);
	return ((int) ft_nbrlen(nbr));
}

int	ft_printu_fd(va_list argp, int fd)
{
	int	nbr;

	nbr = va_arg(argp, int);
	ft_putunbr_fd(nbr, fd);
	return ((int) ft_unbrlen(nbr));
}

int	ft_printx_fd(va_list argp, int fd)
{
	int	nbr;

	nbr = va_arg(argp, int);
	ft_puthex_fd(0, nbr, fd);
	return ((int) ft_hexlen(nbr));
}

int	ft_printbigx_fd(va_list argp, int fd)
{
	int	nbr;

	nbr = va_arg(argp, int);
	ft_puthex_fd(1, nbr, fd);
	return ((int) ft_hexlen(nbr));
}
