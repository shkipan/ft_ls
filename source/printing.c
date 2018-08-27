/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dskrypny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/20 13:31:39 by dskrypny          #+#    #+#             */
/*   Updated: 2018/08/27 19:39:09 by dskrypny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_ls.h"

int				print_m(t_ls *lst)
{
	t_info		*tmp;
	size_t		k;
	char		*delim;

	k = 0;
	tmp = lst->files;
	while (tmp)
	{
		if (k + ft_strlen(tmp->st_name) + lst->blks_width + 1 +
				((tmp->next) ? 2 : 1) > lst->win_param.ws_col)
			k = newline();
		delim = (tmp->next) ? ", " : "\n";
		edit_name(lst, tmp);
		if (CHECK_FLAG(lst->opt, 's'))
			ft_printf("%*zu ", lst->blks_width, tmp->st_blocks);
		ft_printf("%s%s", tmp->st_name, delim);
		k += ft_strlen(tmp->st_name) + ft_strlen(delim);
		tmp = tmp->next;
	}
	if (CHECK_BIT(lst->opt, 28))
		print_recursive(lst);
	return (0);
}

int				print_x(t_ls *lst)
{
	t_info		*tmp;
	size_t		k;
	char		*delim;

	k = 0;
	tmp = lst->files;
	if (CHECK_FLAG(lst->opt, 's'))
		ft_printf("total %zu\n", lst->total);
	while (tmp)
	{
		if (k + lst->tab_width + lst->blks_width +
				((tmp->next) ? 1 : 0) > lst->win_param.ws_col)
			k = newline();
		edit_name(lst, tmp);
		delim = (tmp->next) ? "" : "\n";
		if (CHECK_FLAG(lst->opt, 's'))
			ft_printf("%*zu ", lst->blks_width, tmp->st_blocks);
		ft_printf("%-*s%s", lst->tab_width, tmp->st_name, delim);
		k += lst->tab_width;
		tmp = tmp->next;
	}
	if (CHECK_BIT(lst->opt, 28))
		print_recursive(lst);
	return (0);
}
