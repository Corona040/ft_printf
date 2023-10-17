/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecorona- <ecorona-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 23:18:42 by ecorona-          #+#    #+#             */
/*   Updated: 2023/10/17 10:57:56 by ecorona-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"
# include <stdarg.h>

int	ft_putubase_fd(char *set, long unsigned int n, int fd);
int	ft_printf(const char *format, ...);

typedef union u_data
{
	unsigned long int	i;
	void				*p;
}	t_data;

typedef struct s_flist
{
	t_data	d;
	void	(*f)();
}	t_flist;

#endif
