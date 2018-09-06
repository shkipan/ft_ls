/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   options.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dskrypny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/26 18:30:35 by dskrypny          #+#    #+#             */
/*   Updated: 2018/09/04 14:13:47 by dskrypny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_ls.h"

static int		is_supported(char c)
{
	int i;

	i = -1;
	while (++i < FLAG_COUNT)
		if (SUPPORTED[i] == c)
			return (1);
	return (0);
}

static void		find_last_flag(t_ls *lst, char av)
{
	if (av == 'n')
		lst->last_flag = 'l';
	if (av == 'l' && lst->last_flag != 'n')
		lst->last_flag = 'l';
	if (av == 'x')
		lst->last_flag = 'x';
	if (av == '1')
		lst->last_flag = '1';
	if (av == 'm')
		lst->last_flag = 'm';
	if (av == 'g' || av == 'o')
		lst->last_flag = 'l';
	if (av == 'f')
		lst->opt |= 1;
}

unsigned int	ls_options(t_ls *lst, char *av)
{
	unsigned int	res;
	int				j;

	j = 0;
	res = ft_options(av);
	while (av[++j])
	{
		find_last_flag(lst, av[j]);
		if (av[j] == '1')
			res = SET_BIT(res, 31);
		else if (av[j] == 'C')
			res = SET_BIT(res, 30);
		else if (av[j] == 'F')
			res = SET_BIT(res, 29);
		else if (av[j] == 'R')
			res = SET_BIT(res, 28);
		else if (av[j] == '@')
			res = SET_BIT(res, 27);
		else if (!is_supported(av[j]))
			usage(av[j]);
	}
	if (CHECK_FLAG(res, 'o') || CHECK_FLAG(res, 'g') || CHECK_FLAG(res, 'n'))
		res = SET_BIT(res, 'l' - 'a');
	return (res);
}
