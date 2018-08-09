/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memcmp.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dskrypny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 21:36:23 by dskrypny          #+#    #+#             */
/*   Updated: 2018/06/07 20:37:03 by dskrypny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned const char	*str1;
	unsigned const char	*str2;
	size_t				x;

	str1 = (unsigned const char *)s1;
	str2 = (unsigned const char *)s2;
	while (n-- != 0)
	{
		x = *str1++ - *str2++;
		if (x != 0)
			return (x);
	}
	return (0);
}
