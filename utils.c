/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecorona- <ecorona-@student.42porto.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 10:44:42 by ecorona-          #+#    #+#             */
/*   Updated: 2023/10/18 11:14:38 by ecorona-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putubase_fd(char *set, long unsigned int n, int fd)
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
		//return (nb_digits + 1);
	}
	else
	{
		ft_putchar_fd(set[n], fd);
		//return (1);
	}
}
