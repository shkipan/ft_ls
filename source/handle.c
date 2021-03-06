/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_dir.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dskrypny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/25 16:39:53 by dskrypny          #+#    #+#             */
/*   Updated: 2018/09/27 18:04:51 by dskrypny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_ls.h"

void		create_path(char path[PATH_MAX + 1], char *dir_name,
		char *file_name)
{
	if (file_name[0] == '/')
	{
		ft_strncpy(path, file_name, PATH_MAX);
		return ;
	}
	if (!ft_strcmp(file_name, "."))
	{
		ft_strncpy(path, dir_name, PATH_MAX);
		return ;
	}
	ft_strncpy(path, dir_name, PATH_MAX);
	if (path[ft_strlen(path) - 1] != '/')
		ft_strncat(path, "/", PATH_MAX);
	ft_strncat(path, file_name, PATH_MAX);
}

static int	check_dot(DIR *dirptr, t_dirent *dp, t_dirent **entry, long opt)
{
	if (!CHECK_FLAG(opt, 'a') && dp->d_name[0] == '.')
	{
		readdir_r(dirptr, dp, entry);
		return (1);
	}
	return (0);
}

static void	norm(t_dirent *entry, DIR *dirptr, t_ls *lst)
{
	free(entry);
	closedir(dirptr);
	properties(lst);
	print_files(1, lst);
}

int			handle_file(char *name, t_ls *lst)
{
	char		path[PATH_MAX + 1];
	t_stat		file_info;

	create_path(path, ".", name);
	if (!stat(path, &file_info))
		add_info(lst, path, name, file_info);
	else
		error(lst, name);
	return (1);
}

int			handle_dir(char *name, char *st_name, t_ls *lst)
{
	DIR			*dirptr;
	t_dirent	dp;
	t_dirent	*entry;
	char		path[PATH_MAX + 1];
	t_stat		file_info;

	dirptr = opendir(name);
	if (!dirptr)
		return (error(lst, st_name));
	readdir_r(dirptr, &dp, &entry);
	while (entry)
	{
		if (check_dot(dirptr, &dp, &entry, lst->opt))
			continue ;
		create_path(path, name, dp.d_name);
		if (!lstat(path, &file_info))
			add_info(lst, path, dp.d_name, file_info);
		readdir_r(dirptr, &dp, &entry);
	}
	if (lst->files)
		fix_path(lst, st_name);
	norm(entry, dirptr, lst);
	return (0);
}
