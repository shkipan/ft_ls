/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dskrypny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/20 13:31:39 by dskrypny          #+#    #+#             */
/*   Updated: 2018/09/06 19:37:14 by dskrypny         ###   ########.fr       */
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
		ft_printf("%zu ", tmp->st_ino);
	if (CHECK_FLAG(lst->opt, 's'))
		ft_printf("%*zu ", lst->blks_width, tmp->st_blocks);
	ft_printf("%s%s", tmp->st_name, delim);
	lst->printed_width += lst->blks_width + 1 + ft_strlen(tmp->st_name) +
		ft_strlen(delim);
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
		ft_printf("%zu ", tmp->st_ino);
	if (CHECK_FLAG(lst->opt, 's'))
		ft_printf("%*zu ", lst->blks_width, tmp->st_blocks);
	ft_printf("%-*s%s", lst->tab_width, tmp->st_name, delim);
	lst->printed_width += lst->tab_width + lst->blks_width +
		((tmp->next) ? 1 : 0);
}

void			print_1(t_ls *lst, t_info *tmp)
{
	lst->printed += (lst->printed) ? 0 : 1;
	if (CHECK_FLAG(lst->opt, 'i'))
		ft_printf("%zu ", tmp->st_ino);
	if (CHECK_FLAG(lst->opt, 's'))
		ft_printf("%*zu ", lst->blks_width, tmp->st_blocks);
	ft_printf("%s", tmp->st_name);
	ft_printf("%s", (tmp->st_mode[0] == 'd' && CHECK_FLAG(lst->opt, 'p'))
			? "/" : "");
	ft_putchar('\n');
}
