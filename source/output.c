/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dskrypny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/25 16:39:53 by dskrypny          #+#    #+#             */
/*   Updated: 2018/08/16 21:30:47 by dskrypny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_ls.h"

static int		print_l(t_ls *lst, t_info *tmp)
{
	ft_printf("%s  ", tmp->st_mode);
	ft_printf("%*d ", lst->nlink_width, tmp->st_nlink);
	ft_printf("%*s  %*s  ", lst->user_width, tmp->st_user,
			lst->group_width, tmp->st_group);
	ft_printf("%*d %s\n", lst->size_width, tmp->st_size, tmp->st_name);
	return (0);
}

void			print_info(t_ls *lst)
{
	t_info		*tmp;

	tmp = lst->files;
	while (tmp)
	{
		(CHECK_FLAG(lst->opt, 'l')) ? print_l(lst, tmp) :
			ft_printf("%s\n", tmp->st_name);
		tmp = tmp->next;
	}
}
