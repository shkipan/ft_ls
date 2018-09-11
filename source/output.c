/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dskrypny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/25 16:39:53 by dskrypny          #+#    #+#             */
/*   Updated: 2018/09/11 10:55:30 by dskrypny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_ls.h"

static void		freesher(t_ls *new)
{
	t_info	*tmp;
	t_info	*del;

	tmp = new->files;
	while (tmp)
	{
		free(tmp->st_name);
		free(tmp->st_user);
		free(tmp->st_group);
		free(tmp->st_time);
		free(tmp->full_path);
		if (tmp->xattr_length)
			free(tmp->xattr);
		del = tmp;
		tmp = tmp->next;
		free(del);
	}
	free(new);
}

static void		norminette(t_ls *lst, t_ls *new)
{
	if (CHECK_BIT(lst->opt, 28))
		print_dirs(1, new);
	lst->error = new->error;
	lst->printed = new->printed;
	freesher(new);
}

int				print_dirs(short f, t_ls *lst)
{
	t_info		*tmp;
	t_ls		*new;

	new = NULL;
	tmp = lst->files;
	while (tmp)
	{
		if (tmp->st_mode[0] == 'd' && (!f || (ft_strcmp(tmp->st_name, ".") &&
				ft_strcmp(tmp->st_name, ".."))))
		{
			if (lst->printed > 0)
				ft_putchar('\n');
			if (f && CHECK_BIT(lst->opt, 28))
				ft_printf("%s:\n", tmp->full_path);
			else if (lst->printed || lst->dirs_to_print != 1)
				ft_printf("%s:\n", tmp->st_name);
			init_lst(&new, lst->error, lst->ac, lst->av);
			handle_dir(tmp->full_path, tmp->st_name, new);
			norminette(lst, new);
			lst->printed++;
		}
		tmp = tmp->next;
	}
	return (0);
}

int				print_files(short f, t_ls *lst)
{
	t_info		*tmp;

	tmp = lst->files;
	lst->printed_width = 0;
	if (tmp && ((f && CHECK_FLAG(lst->opt, 's') && lst->last_flag != 'm') ||
			(f && lst->last_flag == 'l')))
		ft_printf("total %zu\n", lst->total);
	while (tmp)
	{
		if (tmp->st_mode[0] == 'd' && !CHECK_FLAG(lst->opt, 'd'))
			lst->dirs_to_print++;
		if (f || (tmp->st_mode[0] != 'd' || CHECK_FLAG(lst->opt, 'd')))
		{
			if (lst->last_flag == 'l')
				print_l(lst, tmp);
			else if (lst->last_flag == 'm')
				print_m(lst, tmp);
			else if (lst->last_flag == 'x')
				print_x(lst, tmp);
			else
				print_1(lst, tmp);
		}
		tmp = tmp->next;
	}
	return (0);
}
