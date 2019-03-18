/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dskrypny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/20 13:31:39 by dskrypny          #+#    #+#             */
/*   Updated: 2019/01/21 15:16:13 by dskrypny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_ls.h"

void			print_m(t_ls *lst, t_info *tmp)
{
	char		*delim;

	lst->printed += (lst->printed) ? 0 : 1;
	if (lst->printed_width + ft_strlen(tmp->st_name) + (lst->blks_width + 1)
			+ ((tmp->next) ? 2 : 1) > lst->win_param.ws_col)
		lst->printed_width = newline();
	delim = (tmp->next) ? ", " : "\n";
	edit_name(lst, tmp);
	if (CHECK_FLAG(lst->opt, 'i'))
		ft_printf("%*zu ", lst->ino_width, tmp->st_ino);
	if (CHECK_FLAG(lst->opt, 's'))
		ft_printf("%*zu ", lst->blks_width, tmp->st_blocks);
	ft_printf("%s%s", tmp->st_name, delim);
	lst->printed_width += (CHECK_FLAG(lst->opt, 's')) ? lst->blks_width + 1 : 0
		+ ft_strlen(tmp->st_name) + ft_strlen(delim);
}

void			print_x(t_ls *lst, t_info *tmp)
{
	char		*delim;

	lst->printed += (lst->printed) ? 0 : 1;
	if (lst->printed_width + lst->tab_width + lst->blks_width +
			((tmp->next) ? 1 : 0) > lst->win_param.ws_col)
		lst->printed_width = newline();
	edit_name(lst, tmp);
	delim = (tmp->next) ? "" : "\n";
	if (CHECK_FLAG(lst->opt, 'i'))
		ft_printf("%*zu ", lst->ino_width, tmp->st_ino);
	if (CHECK_FLAG(lst->opt, 's'))
		ft_printf("%*zu ", lst->blks_width, tmp->st_blocks);
	ft_printf("%-*s%s", lst->tab_width - ((CHECK_FLAG(lst->opt, 's')) ?
				(lst->blks_width + 1) : 0), tmp->st_name, delim);
	lst->printed_width += lst->tab_width + ((tmp->next) ? 1 : 0);
}

void			print_1(t_ls *lst, t_info *tmp)
{
	lst->printed += (lst->printed) ? 0 : 1;
	if (CHECK_FLAG(lst->opt, 'i'))
		ft_printf("%*zu ", lst->ino_width, tmp->st_ino);
	if (CHECK_FLAG(lst->opt, 's'))
		ft_printf("%*zu ", lst->blks_width, tmp->st_blocks);
	print_name(lst, tmp);
	ft_putchar('\n');
}
