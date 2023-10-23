/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecorona- <ecorona-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 23:18:42 by ecorona-          #+#    #+#             */
/*   Updated: 2023/10/20 11:06:25 by ecorona-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"
# include <stdarg.h>

typedef struct s_placeholder
{
	char	placeholder;
	int		(*f)(va_list, int);
}	t_placeholder;

typedef union u_nbr
{
	int					i;
	unsigned int		u;
	long unsigned int	p;
}	t_nbr;

int	ft_printf(const char *format, ...);
int	ft_putbase_fd(char *set, t_nbr n, int fd);
int	ft_printc_fd(va_list argp, int fd);
int	ft_prints_fd(va_list argp, int fd);
int	ft_printp_fd(va_list argp, int fd);
int	ft_printi_fd(va_list argp, int fd);
int	ft_print_fd(const char *format, va_list argp, int fd);

#endif
