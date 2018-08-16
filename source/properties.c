/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   properties.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dskrypny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/16 17:50:21 by dskrypny          #+#    #+#             */
/*   Updated: 2018/08/16 21:30:54 by dskrypny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_ls.h"

void			init_prop(t_ls *lst)
{
	lst->nlink_width = 0;
	lst->size_width = 0;
	lst->user_width = 0;
	lst->group_width = 0;
}

void			properties(t_ls *lst)
{
	t_info	*tmp;

	init_prop(lst);
	tmp = lst->files;
	while (tmp)
	{
		if (lst->nlink_width < ft_count_int(tmp->st_nlink))
			lst->nlink_width = ft_count_int(tmp->st_nlink);
		if (lst->size_width < ft_count_int(tmp->st_size))
			lst->size_width = ft_count_int(tmp->st_size);
		if (lst->user_width < ft_strlen(tmp->st_user))
			lst->user_width = ft_strlen(tmp->st_user);
		if (lst->group_width < ft_strlen(tmp->st_group))
			lst->group_width = ft_strlen(tmp->st_group);
		tmp = tmp->next;
	}
}
