/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dskrypny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/20 13:31:39 by dskrypny          #+#    #+#             */
/*   Updated: 2018/08/20 15:35:38 by dskrypny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_ls.h"

int		print_l(t_ls *lst)
{
	t_info		*tmp;

	tmp = lst->files;
	while (tmp)
	{
		ft_printf("%s  ", tmp->st_mode);
		ft_printf("%*d ", lst->nlink_width, tmp->st_nlink);
		if (!CHECK_FLAG(lst->opt, 'g'))
			(CHECK_FLAG(lst->opt, 'n')) ?
				ft_printf("%*d  ", lst->user_width, tmp->st_uid) :
				ft_printf("%*s  ", lst->user_width, tmp->st_user);
		if (!CHECK_FLAG(lst->opt, 'o'))
			(CHECK_FLAG(lst->opt, 'n')) ?
				ft_printf("%*d  ", lst->group_width, tmp->st_gid) :
				ft_printf("%*s  ", lst->group_width, tmp->st_group);
		ft_printf("%*d ", lst->size_width, tmp->st_size);
		ft_printf("%s %s", tmp->st_time, tmp->st_name);
		ft_printf("%s\n", (tmp->st_mode[0] == 'd' && CHECK_FLAG(lst->opt, 'p'))
				? "/" : "");
		tmp = tmp->next;
	}
	return (0);
}

int		print_m(t_ls *lst)
{
	t_info		*tmp;
	size_t		k;
	char		*delim;

	k = 0;
	tmp = lst->files;
	while (tmp)
	{
		if (k + ft_strlen(tmp->st_name) + ((tmp->next) ? 2 : 1)
				> lst->win_param.ws_col)
		{
			ft_printf("\n");
			k = 0;
		}
		delim = (tmp->next) ? ", " : "\n";
		ft_printf("%s%s%s", tmp->st_name, (tmp->st_mode[0] == 'd' &&
					CHECK_FLAG(lst->opt, 'p')) ? "/" : "", delim);
		k += ft_strlen(tmp->st_name) + ft_strlen(delim);
		tmp = tmp->next;
	}
	return (0);
}