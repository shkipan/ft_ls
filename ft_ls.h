/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dskrypny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/25 16:40:28 by dskrypny          #+#    #+#             */
/*   Updated: 2018/08/27 13:17:35 by dskrypny         ###   ########.fr       */
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
# include <time.h>
# include <sys/ioctl.h>
# include <sys/xattr.h>

# define PATH_MAX 255
# define FLAG_COUNT 17
# define SUPPORTED "afgmlnoprtx1CFRL@"

#define OK ft_printf("ok\n");

typedef struct dirent	t_dirent;
typedef struct stat		t_stat;
typedef struct passwd	t_passwd;
typedef struct group	t_group;
typedef struct timespec	t_timing;
typedef struct winsize	t_winsize;

typedef struct s_info	t_info;

struct			s_info
{
	char			st_type;
	int				st_nlink;
	int				xattr_length;
	size_t			st_uid;
	size_t			st_gid;
	time_t			st_seconds;
	char			*st_user;
	char			*st_group;
	size_t			st_size;
	char			*st_time;
	char			st_mode[12];
	char			*st_name;
	char			*full_path;
	char			*xattr;
	t_info			*prev;
	t_info			*next;
};

typedef struct s_ls		t_ls;

struct			s_ls
{
	char			last_flag;
	unsigned int	opt;
	unsigned int	file_count;
	unsigned int	col_count;
	unsigned int	row_count;
	int				ac;
	size_t			group_width;
	size_t			name_width;
	size_t			nlink_width;
	size_t			size_width;
	size_t			tab_width;
	size_t			user_width;
	size_t			total;
	t_winsize		win_param;
	char			**av;
	t_info			*files;
	t_ls			*next;
};

void			fill_info(t_info **tmp, char *name, t_info *prev, t_stat stats);
void			add_info(t_ls *lst, char *path, char *name, t_stat stats);
int				handle_file(char *name, t_ls *lst);
int				handle_dir(char *name, t_ls *lst);
int				init_lst(t_ls **lst, int ac, char **av);

void			sort_info(t_ls *lst);
void			properties(t_ls *lst);
unsigned int	ls_options(t_ls *lst, char *av);
int				print_info(t_ls *lst);

int				print_m(t_ls *lst);
int				print_l(t_ls *lst);
int				print_x(t_ls *lst);
void			print_recursive(t_ls *lst);

void			usage(char c);
void			error(int c, char *file);

#endif
