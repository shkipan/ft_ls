/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   options.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dskrypny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/26 18:30:35 by dskrypny          #+#    #+#             */
/*   Updated: 2018/08/09 20:40:18 by dskrypny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_ls.h"

int				is_supported(char c)
{
	int i;

	i = -1;
	while (++i < 2)
		if (SUPPORTED[i] == c)
			return (1);
	return (0);
}

unsigned int	ls_options(char *av)
{
	unsigned int	res;
	int				j;

	j = 0;
	res = ft_options(av);
	while (av[++j])
	{
		if (av[j] == '1')
			res = SET_BIT(res, 31);
		else if (av[j] == 'C')
			res = SET_BIT(res, 30);
		else if (av[j] == 'F')
			res = SET_BIT(res, 29);
		else if (av[j] == 'R')
			res = SET_BIT(res, 28);
		else if (!is_supported(av[j]))
			usage(av[j]);
	}
	return (res);
}
