/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dskrypny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/14 21:56:51 by dskrypny          #+#    #+#             */
/*   Updated: 2018/09/01 20:20:43 by dskrypny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_ls.h"

static void		create_info(t_ls *lst, char *name, t_stat stats)
{
	t_info	**tmp;

	tmp = &(lst->files);
	*tmp = (t_info *)malloc(sizeof(t_info));
	fill_info(tmp, name, NULL, stats);
}

void			add_info(t_ls *lst, char *path, char *name, t_stat stats)
{
	t_info	**tmp;
	t_info	*prev;

	tmp = &(lst->files);
	if (!*tmp)
		create_info(lst, name, stats);
	else
	{
		while (*tmp)
		{
			prev = *tmp;
			tmp = &(*tmp)->next;
		}
		*tmp = (t_info *)malloc(sizeof(t_info));
		(*tmp)->full_path = ft_strdup(path);
		fill_info(tmp, name, prev, stats);
	}
	lst->file_count++;
}
