/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_info.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dskrypny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/11 11:02:08 by dskrypny          #+#    #+#             */
/*   Updated: 2018/09/11 11:04:23 by dskrypny         ###   ########.fr       */
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
	size_t	temp_ino;
	int		temp_chmod[3];
	short	i;

	i = -1;
	while (++i < 3)
		temp_chmod[i] = t1->chmod[i];
	temp_blocks = t1->st_blocks;
	temp_ino = t1->st_ino;
	i = -1;
	while (++i < 3)
		t1->chmod[i] = t2->chmod[i];
	t1->st_blocks = t2->st_blocks;
	t1->st_ino = t2->st_ino;
	i = -1;
	while (++i < 3)
		t2->chmod[i] = temp_chmod[i];
	t2->st_blocks = temp_blocks;
	t2->st_ino = temp_ino;
}

static void		swap_info3(t_info *t1, t_info *t2)
{
	int		temp_dev[2];

	temp_dev[0] = t1->dev[0];
	temp_dev[1] = t1->dev[1];
	t1->dev[0] = t2->dev[0];
	t1->dev[1] = t2->dev[1];
	t2->dev[0] = temp_dev[0];
	t2->dev[1] = temp_dev[1];
}

void			swap_info(t_info *t1, t_info *t2)
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
	swap_info3(t1, t2);
}
