/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_dir.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dskrypny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/25 16:39:53 by dskrypny          #+#    #+#             */
/*   Updated: 2018/08/20 15:35:36 by dskrypny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_ls.h"

void	create_path(char path[PATH_MAX + 1], char *dir_name, char *file_name)
{
	ft_strncpy(path, dir_name, PATH_MAX);
	ft_strncat(path, "/", PATH_MAX);
	ft_strncat(path, file_name, PATH_MAX);
}

int		check_dot(DIR *dirptr, t_dirent *dp, t_dirent **entry, long opt)
{
	if (!CHECK_FLAG(opt, 'a') && dp->d_name[0] == '.')
	{
		readdir_r(dirptr, dp, entry);
		return (1);
	}
	return (0);
}

int		handle_file(char *name, t_ls *lst)
{
	char		path[PATH_MAX + 1];
	t_stat		file_info;

	create_path(path, ".", name);
	if (!stat(path, &file_info))
		add_info(lst, name, file_info);
	else
		error(1, name);
	return (1);
}

int		handle_dir(char *name, t_ls *lst)
{
	DIR			*dirptr;
	t_dirent	dp;
	t_dirent	*entry;
	char		path[PATH_MAX + 1];
	t_stat		file_info;

	lst += 0;
	dirptr = opendir(name);
	if (!dirptr)
		return (handle_file(name, lst));
	readdir_r(dirptr, &dp, &entry);
	while (entry)
	{
		if (check_dot(dirptr, &dp, &entry, lst->opt))
			continue ;
		create_path(path, name, dp.d_name);
		if (!lstat(path, &file_info))
			add_info(lst, dp.d_name, file_info);
		readdir_r(dirptr, &dp, &entry);
	}
	free(entry);
	closedir(dirptr);
	if (!CHECK_FLAG(lst->opt, 'f'))
		sort_info(lst);
	return (0);
}
