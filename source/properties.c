/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   properties.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dskrypny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/16 17:50:21 by dskrypny          #+#    #+#             */
/*   Updated: 2018/08/20 14:20:01 by dskrypny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_ls.h"

static void		init_prop(t_ls *lst)
{
	lst->tab_width = 8;
	lst->name_width = 0;
	lst->nlink_width = 0;
	lst->size_width = 0;
	lst->user_width = 0;
	lst->group_width = 0;
	lst->col_count = 1;
	lst->row_count = lst->file_count;
	if (CHECK_FLAG(lst->opt, 'n'))
		lst->opt |= SET_BIT(lst->opt, 'l' - 'a');
}

static void		modify_output(t_ls *lst)
{
	while (lst->name_width >= lst->tab_width)
		lst->tab_width += 8;
}

static void		count_params(t_ls *lst, t_info *tmp)
{
	if (lst->nlink_width < ft_count_int(tmp->st_nlink))
		lst->nlink_width = ft_count_int(tmp->st_nlink);
	if (lst->name_width < ft_strlen(tmp->st_name))
		lst->name_width = ft_strlen(tmp->st_name);
	if (lst->size_width < ft_count_int(tmp->st_size))
		lst->size_width = ft_count_int(tmp->st_size);
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

void			properties(t_ls *lst)
{
	t_info	*tmp;
	size_t	length;

	init_prop(lst);
	tmp = lst->files;
	while (tmp)
	{
		count_params(lst, tmp);
		tmp->st_time = ft_strchr(tmp->st_time, ' ') + 1;
		length = ft_strlen(tmp->st_time) -
			ft_strlen(ft_strrchr(tmp->st_time, ':'));
		tmp->st_time[length] = '\0';
		tmp = tmp->next;
	}
	modify_output(lst);
}
