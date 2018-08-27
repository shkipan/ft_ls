/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dskrypny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/25 16:39:53 by dskrypny          #+#    #+#             */
/*   Updated: 2018/08/27 13:30:26 by dskrypny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_ls.h"

void			print_win(t_ls lst)
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
			init_lst(&new, lst->ac, lst->av);
			ft_printf("\n%s:\n", tmp->full_path);
			handle_dir(tmp->full_path, new);
			freesher(new);
		}
		i++;
		tmp = tmp->next;
	}
}

int				print_info(t_ls *lst)
{
	t_info		*tmp;

	if (lst->last_flag == 'l')
		return (print_l(lst));
	if (lst->last_flag == 'm')
		return (print_m(lst));
	if (lst->last_flag == 'x')
		return (print_x(lst));
	tmp = lst->files;
	while (tmp)
	{
		ft_printf("%s", tmp->st_name);
		ft_printf("%s\n", (tmp->st_mode[0] == 'd' && CHECK_FLAG(lst->opt, 'p'))
				? "/" : "");
		tmp = tmp->next;
	}
	if (CHECK_BIT(lst->opt, 28))
		print_recursive(lst);
	return (0);
}
