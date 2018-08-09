/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dskrypny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/18 18:51:52 by dskrypny          #+#    #+#             */
/*   Updated: 2018/06/24 14:42:28 by dskrypny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_sym(size_t n)
{
	int		i;

	i = 0;
	while (n / 10 > 0)
	{
		n = n / 10;
		i++;
	}
	i++;
	return (i);
}

char		*ft_itoa_uns(size_t n)
{
	char			*res;
	size_t			ex;
	int				size;
	int				i;
	size_t			val;

	i = 0;
	ex = 1;
	val = n;
	size = ft_count_sym(val);
	if (!(res = (char *)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	while (val / ex > 9)
		ex *= 10;
	while (ex >= 1)
	{
		res[i++] = '0' + val / ex;
		val = val % ex;
		ex /= 10;
	}
	res[i] = '\0';
	return (res);
}
