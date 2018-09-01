/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dskrypny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/25 16:39:53 by dskrypny          #+#    #+#             */
/*   Updated: 2018/09/01 20:47:36 by dskrypny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_ls.h"

void			print_win(t_ls *lst)
{
	ft_printf("%d files max width %d suggested tab %d\n",
			lst->file_count, lst->name_width, lst->tab_width);
	ft_printf("win_width = %d win_heigth = %d cols %d rows %d\n",
			lst->win_param.ws_col, lst->win_param.ws_row,
			lst->col_count, lst->row_count);
	ft_printf("last flag %c\n", lst->last_flag);
}

void			freesher(t_ls *new)
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

void			print_recursive(t_ls *lst)
{
	t_info		*tmp;
	t_ls		*new;
	size_t		i;

	i = 0;
	tmp = lst->files;
	while (i < lst->file_count)
	{
		if (tmp->st_mode[0] == 'd')
		{
			new = lst->next;
			init_lst(&new, lst->error, lst->ac, lst->av);
			ft_printf("\n%s:\n", tmp->full_path);
			handle_dir(tmp->full_path, tmp->st_name, new);
			freesher(new);
		}
		i++;
		tmp = tmp->next;
	}
}

int				print_dirs(t_ls *lst)
{
	t_info		*tmp;
	t_ls		*new;

	new = NULL;
	tmp = lst->files;
	while (tmp)
	{
		if (tmp->st_mode[0] == 'd')
		{
			if (lst->printed > 0)
				ft_putchar('\n');
			if (lst->printed || lst->dirs_to_print != 1)
				ft_printf("%s:\n", tmp->st_name);
			init_lst(&new, lst->error, lst->ac, lst->av);
			handle_dir(tmp->full_path, tmp->st_name, new);
			lst->error = new->error;
			lst->printed = new->printed;
			freesher(new);
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
	if (f && CHECK_FLAG(lst->opt, 's') && lst->last_flag == 'x')
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
