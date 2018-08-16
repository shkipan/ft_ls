/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dskrypny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/25 16:40:28 by dskrypny          #+#    #+#             */
/*   Updated: 2018/08/16 21:29:39 by dskrypny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include "libft/libft.h"

# include <sys/types.h>
# include <sys/stat.h>
# include <dirent.h>
# include <pwd.h>
# include <grp.h>

# define PATH_MAX 255
# define SUPPORTED "al1CFR"

typedef struct dirent	t_dirent;
typedef struct stat		t_stat;
typedef struct passwd	t_passwd;
typedef struct group	t_group;

typedef struct s_info	t_info;

struct			s_info
{
	char			st_mode[11];
	int				st_nlink;
	char			*st_user;
	char			*st_group;
	size_t			st_size;
	char			*st_name;
	t_info			*prev;
	t_info			*next;
};

typedef struct	s_ls
{
	unsigned int	opt;
	size_t			nlink_width;
	size_t			size_width;
	size_t			user_width;
	size_t			group_width;
	size_t			total;
	t_info			*files;
}				t_ls;

void			add_info(t_ls *lst, char *name, t_stat stats);
int				handle_file(char *name, t_ls *lst);
int				handle_dir(char *name, t_ls *lst);

void			sort_info(t_ls *lst);
void			properties(t_ls *lst);
unsigned int	ls_options(char *av);
void			print_info(t_ls *lst);

void			usage(char c);
void			error(int c, char *file);

#endif
