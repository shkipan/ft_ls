/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dskrypny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/16 13:46:40 by dskrypny          #+#    #+#             */
/*   Updated: 2018/08/27 15:07:46 by dskrypny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_ls.h"

static void		swap_mode(t_info *t1, t_info *t2)
{
	char	c;
	int		i;
	time_t	temp_seconds;
	char	*temp_user;
	char	*temp_group;

	i = -1;
	while (++i < 10)
	{
		c = t1->st_mode[i];
		t1->st_mode[i] = t2->st_mode[i];
		t2->st_mode[i] = c;
	}
	temp_seconds = t1->st_seconds;
	temp_user = t1->st_user;
	temp_group = t1->st_group;
	t1->st_seconds = t2->st_seconds;
	t1->st_user = t2->st_user;
	t1->st_group = t2->st_group;
	t2->st_seconds = temp_seconds;
	t2->st_user = temp_user;
	t2->st_group = temp_group;
}

static void		swap_info2(t_info *t1, t_info *t2)
{
	size_t	temp_blocks;

	temp_blocks = t1->st_blocks;
	t1->st_blocks = t2->st_blocks;
	t2->st_blocks = temp_blocks;
}

static void		swap_info(t_info *t1, t_info *t2)
{
	char	*temp_name;
	char	*temp_path;
	char	*temp_time;
	size_t	temp_size;
	int		temp_nlink;

	temp_name = t1->st_name;
	temp_path = t1->full_path;
	temp_time = t1->st_time;
	temp_size = t1->st_size;
	temp_nlink = t1->st_nlink;
	t1->st_name = t2->st_name;
	t1->full_path = t2->full_path;
	t1->st_time = t2->st_time;
	t1->st_size = t2->st_size;
	t1->st_nlink = t2->st_nlink;
	t2->st_name = temp_name;
	t2->full_path = temp_path;
	t2->st_time = temp_time;
	t2->st_size = temp_size;
	t2->st_nlink = temp_nlink;
	swap_mode(t1, t2);
	swap_info2(t1, t2);
}

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
	if (CHECK_FLAG(lst->opt, 't'))
		return (sort_time(lst));
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
}
