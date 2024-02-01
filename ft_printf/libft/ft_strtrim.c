/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecorona- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 09:08:13 by ecorona-          #+#    #+#             */
/*   Updated: 2023/10/11 09:29:36 by ecorona-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	isin(char c, char const *set)
{
	while (*set)
	{
		if (*set == c)
			return (1);
		set++;
	}
	return (0);
}

static int	inis(char c, char const *set)
{
	set += ft_strlen(set) - 1;
	while (*set)
	{
		if (*set == c)
			return (1);
		set--;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*trim;
	size_t	start;
	size_t	end;

	start = 0;
	end = ft_strlen(s1) - 1;
	while (isin(s1[start], set))
		start++;
	while (inis(s1[end], set))
		end--;
	trim = ft_substr(s1, start, end - start + 1);
	if (!trim)
		return (0);
	return (trim);
}

/*
#include <stdio.h>

int	main(void)
{
	char	*s1 = ";lkj;lkjbananajlkj;";
	char	*set = "jkl;";

	printf("%s\n", ft_strtrim(s1, set));
}
*/
