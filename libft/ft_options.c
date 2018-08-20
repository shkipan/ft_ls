/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   options.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dskrypny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/26 18:30:35 by dskrypny          #+#    #+#             */
/*   Updated: 2018/08/20 13:37:57 by dskrypny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int	ft_options(char *av)
{
	unsigned int	res;
	int				j;

	j = 0;
	res = 0;
	while (av[++j])
	{
		if (av[j] <= 'z' && av[j] >= 'a')
			res = SET_BIT(res, av[j] - 'a');
	}
	return (res);
}
