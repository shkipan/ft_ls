/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_slash.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dskrypny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/27 19:25:04 by dskrypny          #+#    #+#             */
/*   Updated: 2018/09/06 19:41:12 by dskrypny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_ls.h"

size_t		newline(void)
{
	ft_printf("\n");
	return (0);
}

void		edit_name(t_ls *lst, t_info *tmp)
{
	char	*del;

	if (!CHECK_FLAG(lst->opt, 'p'))
		return ;
	if (tmp->st_mode[0] == 'd')
	{
		del = tmp->st_name;
		tmp->st_name = ft_strjoin(tmp->st_name, "/");
		free(del);
	}
}

void		print_win(t_ls *lst)
{
	ft_printf("%d files max width %d suggested tab %d\n",
			lst->file_count, lst->name_width, lst->tab_width);
	ft_printf("win_width = %d win_heigth = %d cols %d rows %d\n",
			lst->win_param.ws_col, lst->win_param.ws_row,
			lst->col_count, lst->row_count);
	ft_printf("last flag %c\n", lst->last_flag);
}
