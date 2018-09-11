/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   properties.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dskrypny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/16 17:50:21 by dskrypny          #+#    #+#             */
/*   Updated: 2018/09/07 16:34:24 by dskrypny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_ls.h"

static void		init_prop(t_ls *lst)
{
	lst->tab_width = 8;
	lst->name_width = 0;
	lst->nlink_width = 0;
	lst->size_width = 0;
	lst->ino_width = 0;
	lst->user_width = 0;
	lst->group_width = 0;
	lst->blks_width = 0;
	lst->col_count = 1;
	lst->row_count = lst->file_count;
}

static void		check_link(t_info *tmp)
{
	char	*buf;

	if (tmp->st_mode[0] != 'l')
		return ;
	buf = (char *)malloc(sizeof(char) * (256));
	readlink(tmp->full_path, buf, 255);
	tmp->st_link = buf;
}

static void		count_params_width(t_ls *lst, t_info *tmp)
{
	if (lst->nlink_width < ft_count_int(tmp->st_nlink))
		lst->nlink_width = ft_count_int(tmp->st_nlink);
	if (lst->name_width < ft_strlen(tmp->st_name))
		lst->name_width = ft_strlen(tmp->st_name);
	if (lst->size_width < ft_count_int(tmp->st_size))
		lst->size_width = ft_count_int(tmp->st_size);
	if (lst->blks_width < ft_count_int(tmp->st_blocks))
		lst->blks_width = ft_count_int(tmp->st_blocks);
	if (lst->ino_width < ft_count_int(tmp->st_ino))
		lst->ino_width = ft_count_int(tmp->st_ino);
	if (CHECK_FLAG(lst->opt, 'n'))
	{
		if (lst->user_width < ft_count_int(tmp->st_uid))
			lst->user_width = ft_count_int(tmp->st_uid);
		if (lst->group_width < ft_count_int(tmp->st_gid))
			lst->group_width = ft_count_int(tmp->st_gid);
	}
	else
	{
		if (lst->user_width < ft_strlen(tmp->st_user))
			lst->user_width = ft_strlen(tmp->st_user);
		if (lst->group_width < ft_strlen(tmp->st_group))
			lst->group_width = ft_strlen(tmp->st_group);
	}
}

static void		check_attr(t_info **tmp)
{
	char	*buf;
	int		c;

	buf = NULL;
	c = listxattr((*tmp)->full_path, NULL, 255, 0);
	if (c > 0)
	{
		buf = (char *)malloc(sizeof(char) * (c + 1));
		c = listxattr((*tmp)->full_path, buf, c, 0);
		(*tmp)->st_mode[10] = '@';
		(*tmp)->xattr = ft_strdup(buf);
		(*tmp)->xattr_length = c;
	}
	free(buf);
}

void			properties(t_ls *lst)
{
	t_info	*tmp;
	size_t	length;
	char	*del;

	if (!CHECK_FLAG(lst->opt, 'f'))
		sort_info(lst);
	init_prop(lst);
	tmp = lst->files;
	while (tmp)
	{
		check_link(tmp);
		lst->total += tmp->st_blocks;
		count_params_width(lst, tmp);
		check_attr(&tmp);
		del = tmp->st_time;
		tmp->st_time = ft_strdup(ft_strchr(tmp->st_time, ' ') + 1);
		free(del);
		length = ft_strlen(tmp->st_time) -
			ft_strlen(ft_strrchr(tmp->st_time, ':'));
		tmp->st_time[length] = '\0';
		tmp = tmp->next;
	}
	while (lst->name_width >= lst->tab_width)
		lst->tab_width += 8;
}
