/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dskrypny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/25 16:39:53 by dskrypny          #+#    #+#             */
/*   Updated: 2018/08/20 15:08:13 by dskrypny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_ls.h"

static void	handle_files(t_ls **lst, int ac, char **av)
{
	int				i;

	i = 0;
	*lst = (t_ls *)malloc(sizeof(t_ls));
	(*lst)->opt = 0;
	(*lst)->file_count = 0;
	(*lst)->files = NULL;
	(*lst)->last_flag = '1';
	ioctl(0, TIOCGWINSZ, &((*lst)->win_param));
	while (++i < ac && av[i][0] == '-')
		(*lst)->opt |= (av[i][0] == '-') ? ls_options(*lst, av[i]) : 0;
	if (CHECK_FLAG((*lst)->opt, 'o') || CHECK_FLAG((*lst)->opt, 'g')
			|| CHECK_FLAG((*lst)->opt, 'n'))
		(*lst)->opt |= SET_BIT((*lst)->opt, 'l' - 'a');
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

	handle_files(&lst, ac, av);
	properties(lst);
	print_info(lst);
	//system("leaks ft_ls");
	return (0);
}
