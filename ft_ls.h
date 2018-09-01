/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dskrypny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/25 16:40:28 by dskrypny          #+#    #+#             */
/*   Updated: 2018/09/01 20:30:34 by dskrypny         ###   ########.fr       */
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
# define FLAG_COUNT 18
# define SUPPORTED "adfgmlnoprstx1CFRL@"

#define OK ft_printf("ok\n");
# define LE system("leaks ft_ls");

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
	size_t			st_size;
	blkcnt_t		st_blocks;
	time_t			st_seconds;
	char			*st_user;
	char			*st_group;
	char			*st_time;
	char			*st_link;
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
	char			error;
	char			printed;
	char			last_flag;
	unsigned int	opt;
	unsigned int	file_count;
	unsigned int	col_count;
	unsigned int	row_count;
	int				ac;
	int				dirs_to_print;
	size_t			group_width;
	size_t			name_width;
	size_t			nlink_width;
	size_t			printed_width;
	size_t			size_width;
	size_t			tab_width;
	size_t			user_width;
	size_t			blks_width;
	size_t			total;
	t_winsize		win_param;
	char			**av;
	t_info			*files;
	t_ls			*next;
};

void			fill_info(t_info **tmp, char *name, t_info *prev, t_stat stats);
void			add_info(t_ls *lst, char *path, char *name, t_stat stats);
int				handle_file(char *name, t_ls *lst);
int				handle_dir(char *name, char *st_name, t_ls *lst);
int				init_lst(t_ls **lst, char err, int ac, char **av);

void			sort_info(t_ls *lst);
void			properties(t_ls *lst);
unsigned int	ls_options(t_ls *lst, char *av);
int				print_files(short flag, t_ls *lst);
int				print_dirs(t_ls *lst);

void			create_path(char path[PATH_MAX + 1], char *dir_name,
		char *file_name);
void			fix_path(t_ls *lst);

void			print_m(t_ls *lst, t_info *tmp);
void			print_l(t_ls *lst, t_info *tmp);
void			print_x(t_ls *lst, t_info *tmp);
void			print_1(t_ls *lst, t_info *tmp);
void			print_recursive(t_ls *lst);

void			usage(char c);
int				error(t_ls *lst, char *file);
void			edit_name(t_ls *lst, t_info *tmp);
size_t			newline(void);

#endif
