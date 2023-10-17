/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecorona- <ecorona-@student.42porto.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 10:24:47 by ecorona-          #+#    #+#             */
/*   Updated: 2023/10/17 10:33:19 by ecorona-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	main(void)
{
	t_data	data;
	t_flist	flist;

	data.i = 100;
	flist.d = data;
	flist.f = &ft_putnbr_fd;
	flist.f((flist.d).i, 1);
}
