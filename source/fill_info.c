/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_info.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dskrypny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/17 17:58:25 by dskrypny          #+#    #+#             */
/*   Updated: 2018/08/18 17:56:06 by dskrypny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_ls.h"

static char	choose_type(mode_t mode)
{
	if (S_ISBLK(mode))
		return ('b');
	else if (S_ISCHR(mode))
		return ('c');
	else if (S_ISDIR(mode))
		return ('d');
	else if (S_ISLNK(mode))
		return ('l');
	else if (S_ISSOCK(mode))
		return ('s');
	else if (S_ISFIFO(mode))
		return ('p');
	return ('-');
}

static void	fill_mode(t_info **tmp, mode_t mode)
{
	int				i;
	const char		str[] = "rwxrwxrwx";

	i = 0;
	(*tmp)->st_mode[i] = choose_type(mode);
	while (++i < 10)
		(*tmp)->st_mode[i] = (CHECK_BIT(mode, 9 - i)) ? str[i - 1] : '-';
	(*tmp)->st_mode[i] = '\0';
}

static void	fill_user(t_info **tmp, t_stat stats)
{
	t_passwd	*u_struc;
	t_group		*g_struc;

	if (!(u_struc = getpwuid(stats.st_uid)))
		return ;
	(*tmp)->st_uid = stats.st_uid;
	(*tmp)->st_user = ft_strdup(u_struc->pw_name);
	if (!(g_struc = getgrgid(stats.st_gid)))
		return ;
	(*tmp)->st_gid = stats.st_gid;
	(*tmp)->st_group = ft_strdup(g_struc->gr_name);
}

void		fill_info(t_info **tmp, char *name, t_info *prev, t_stat stats)
{
	(*tmp)->st_name = ft_strdup(name);
	(*tmp)->st_size = stats.st_size;
	(*tmp)->st_nlink = stats.st_nlink;
	(*tmp)->st_time = ft_strdup(ctime(&stats.st_mtimespec.tv_sec));
	fill_mode(tmp, stats.st_mode);
	fill_user(tmp, stats);
	(*tmp)->prev = prev;
	(*tmp)->next = NULL;
}
