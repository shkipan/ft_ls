/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dskrypny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/16 13:46:40 by dskrypny          #+#    #+#             */
/*   Updated: 2018/09/11 11:02:01 by dskrypny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_ls.h"

void			sort_time(t_ls *lst)
{
	t_info		*tmp1;
	t_info		*tmp2;

	if (!lst->files)
		return ;
	tmp1 = lst->files;
	while (tmp1->next)
	{
		tmp2 = tmp1->next;
		while (tmp2)
		{
			if (!CHECK_FLAG(lst->opt, 'r') &&
					tmp1->st_seconds < tmp2->st_seconds)
				swap_info(tmp1, tmp2);
			if (CHECK_FLAG(lst->opt, 'r') &&
					tmp1->st_seconds > tmp2->st_seconds)
				swap_info(tmp1, tmp2);
			if (tmp1->st_seconds == tmp2->st_seconds &&
					ft_strcmp(tmp1->st_name, tmp2->st_name) > 0)
				swap_info(tmp1, tmp2);
			tmp2 = tmp2->next;
		}
		tmp1 = tmp1->next;
	}
}

void			sort_info(t_ls *lst)
{
	t_info		*tmp1;
	t_info		*tmp2;

	if (!lst->files)
		return ;
	tmp1 = lst->files;
	while (tmp1->next)
	{
		tmp2 = tmp1->next;
		while (tmp2)
		{
			if (!CHECK_FLAG(lst->opt, 'r') &&
					ft_strcmp(tmp1->st_name, tmp2->st_name) > 0)
				swap_info(tmp1, tmp2);
			if (CHECK_FLAG(lst->opt, 'r') &&
					ft_strcmp(tmp1->st_name, tmp2->st_name) < 0)
				swap_info(tmp1, tmp2);
			tmp2 = tmp2->next;
		}
		tmp1 = tmp1->next;
	}
	if (CHECK_FLAG(lst->opt, 't'))
		return (sort_time(lst));
}
