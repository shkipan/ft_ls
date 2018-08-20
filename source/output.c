/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dskrypny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/25 16:39:53 by dskrypny          #+#    #+#             */
/*   Updated: 2018/08/20 15:16:31 by dskrypny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_ls.h"

int				print_info(t_ls *lst)
{
	t_info		*tmp;

	if (lst->last_flag == 'l')
		return (print_l(lst));
	if (lst->last_flag == 'm')
		return (print_m(lst));
	tmp = lst->files;
	while (tmp)
	{
		ft_printf("%s", tmp->st_name);
		ft_printf("%s\n", (tmp->st_mode[0] == 'd' && CHECK_FLAG(lst->opt, 'p'))
				? "/" : "");
		tmp = tmp->next;
	}
	ft_printf("%d files max width %d suggested tab %d\n",
			lst->file_count, lst->name_width, lst->tab_width);
	ft_printf("win_width = %d win_heigth = %d cols %d rows %d\n",
			lst->win_param.ws_col, lst->win_param.ws_row,
			lst->col_count, lst->row_count);
	ft_printf("last flag %c\n", lst->last_flag);
	return (0);
}
