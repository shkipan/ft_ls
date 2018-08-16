/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dskrypny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/25 16:39:53 by dskrypny          #+#    #+#             */
/*   Updated: 2018/08/16 21:29:28 by dskrypny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_ls.h"

static void	fill_info(t_ls **lst, int ac, char **av)
{
	int				i;

	i = 0;
	*lst = (t_ls *)malloc(sizeof(t_ls));
	(*lst)->opt = 0;
	(*lst)->files = NULL;
	while (++i < ac && av[i][0] == '-')
		(*lst)->opt |= (av[i][0] == '-') ? ls_options(av[i]) : 0;
	if (ac == 1 || i == ac)
		handle_dir(".", *lst);
	else
	{
		i--;
		while (++i < ac)
			handle_dir(av[i], *lst);
	}
}

int			main(int ac, char **av)
{
	t_ls			*lst;

	fill_info(&lst, ac, av);
	sort_info(lst);
	properties(lst);
	print_info(lst);
	return (0);
}
