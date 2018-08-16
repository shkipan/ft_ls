/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dskrypny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/14 21:56:51 by dskrypny          #+#    #+#             */
/*   Updated: 2018/08/16 21:31:12 by dskrypny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_ls.h"

static char	choose_type(mode_t mode)
{
	if (S_ISDIR(mode))
		return ('d');
	return ('-');
}

void		fill_mode(t_info **tmp, mode_t mode)
{
	int				i;
	const char		str[] = "rwxrwxrwx";

	i = 0;
	(*tmp)->st_mode[i] = choose_type(mode);
	while (++i < 10)
		(*tmp)->st_mode[i] = (CHECK_BIT(mode, 9 - i)) ? str[i - 1] : '-';
	(*tmp)->st_mode[i] = '\0';
}

void		fill_user(t_info **tmp, uid_t uid, gid_t gid)
{
	t_passwd	*u_struc;
	t_group		*g_struc;

	if (!(u_struc = getpwuid(uid)))
		return ;
	(*tmp)->st_user = ft_strdup(u_struc->pw_name);
	if (!(g_struc = getgrgid(gid)))
		return ;
	(*tmp)->st_group = ft_strdup(g_struc->gr_name);
}

static void	fill_info(t_info **tmp, char *name, t_info *prev, t_stat stats)
{
	(*tmp)->st_name = ft_strdup(name);
	(*tmp)->st_size = stats.st_size;
	(*tmp)->st_nlink = stats.st_nlink;
	fill_mode(tmp, stats.st_mode);
	fill_user(tmp, stats.st_uid, stats.st_gid);
	(*tmp)->prev = prev;
	(*tmp)->next = NULL;
}

static void	create_info(t_ls *lst, char *name, t_stat stats)
{
	t_info	**tmp;

	tmp = &(lst->files);
	*tmp = (t_info *)malloc(sizeof(t_info));
	fill_info(tmp, name, NULL, stats);
}

void		add_info(t_ls *lst, char *name, t_stat stats)
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
		fill_info(tmp, name, prev, stats);
	}
}
