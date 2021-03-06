/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_l.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dskrypny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/27 19:29:38 by dskrypny          #+#    #+#             */
/*   Updated: 2019/01/21 15:16:47 by dskrypny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_ls.h"

static void		l_stuff(t_ls *lst, t_info *tmp)
{
	if (!CHECK_FLAG(lst->opt, 'g'))
		(CHECK_FLAG(lst->opt, 'n')) ?
			ft_printf("%-*d  ", lst->user_width, tmp->st_uid) :
			ft_printf("%-*s  ", lst->user_width, tmp->st_user);
	if (!CHECK_FLAG(lst->opt, 'o'))
		(CHECK_FLAG(lst->opt, 'n')) ?
			ft_printf("%-*d  ", lst->group_width, tmp->st_gid) :
			ft_printf("%-*s  ", lst->group_width, tmp->st_group);
	ft_printf("%*d ", lst->size_width, tmp->st_size);
	edit_name(lst, tmp);
	ft_printf("%s %s", tmp->st_time, tmp->st_name);
	(tmp->st_mode[0] == 'l') ? ft_printf(" -> %s\n", tmp->st_link) :
		ft_putchar('\n');
	if (CHECK_BIT(lst->opt, 27) && tmp->xattr_length > 0)
		ft_printf("\t%s\t%d\n", tmp->xattr, tmp->xattr_length);
}

void			print_l(t_ls *lst, t_info *tmp)
{
	lst->printed += (lst->printed) ? 0 : 1;
	if (CHECK_FLAG(lst->opt, 'i'))
		ft_printf("%*zu ", lst->ino_width, tmp->st_ino);
	if (CHECK_FLAG(lst->opt, 's'))
		ft_printf("%*zu ", lst->blks_width, tmp->st_blocks);
	ft_printf("%s ", tmp->st_mode);
	ft_printf("%*d ", lst->nlink_width, tmp->st_nlink);
	l_stuff(lst, tmp);
}
