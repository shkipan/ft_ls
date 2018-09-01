/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dskrypny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/25 16:39:53 by dskrypny          #+#    #+#             */
/*   Updated: 2018/09/01 20:46:56 by dskrypny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_ls.h"

int			init_lst(t_ls **lst, char err, int ac, char **av)
{
	int				i;

	i = 0;
	*lst = (t_ls *)malloc(sizeof(t_ls));
	(*lst)->ac = ac;
	(*lst)->av = av;
	(*lst)->opt = 0;
	(*lst)->error = err;
	(*lst)->printed = 0;
	(*lst)->printed_width = 0;
	(*lst)->dirs_to_print = 0;
	(*lst)->total = 0;
	(*lst)->file_count = 0;
	(*lst)->files = NULL;
	(*lst)->last_flag = '1';
	ioctl(0, TIOCGWINSZ, &((*lst)->win_param));
	while (++i < ac && av[i][0] == '-')
		(*lst)->opt |= (av[i][0] == '-') ? ls_options(*lst, av[i]) : 0;
	if (CHECK_FLAG((*lst)->opt, 'o') || CHECK_FLAG((*lst)->opt, 'g')
			|| CHECK_FLAG((*lst)->opt, 'n'))
		(*lst)->opt |= SET_BIT(0, 'l' - 'a');
	(*lst)->next = NULL;
	return (i);
}

void		fix_path(t_ls *lst)
{
	char	path[PATH_MAX + 1];

	create_path(path, ".", lst->files->st_name);
	lst->files->full_path = ft_strdup(path);
}

int			main(int ac, char **av)
{
	t_ls			*lst;
	int				i;

	i = init_lst(&lst, 0, ac, av);
	if (ac == 1 || i == ac)
		handle_file(".", lst);
	else
	{
		i--;
		while (++i < ac)
			handle_file(av[i], lst);
	}
	fix_path(lst);
	properties(lst);
	print_files(0, lst);
	if (lst->dirs_to_print)
		print_dirs(lst);
	return (lst->error);
}
