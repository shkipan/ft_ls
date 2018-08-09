/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dskrypny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/25 16:40:28 by dskrypny          #+#    #+#             */
/*   Updated: 2018/08/09 21:02:12 by dskrypny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include "libft/libft.h"

# include <sys/types.h>
# include <sys/stat.h>
# include <dirent.h>

# define PATH_MAX 255
# define SUPPORTED "al1CFR"

typedef struct	dirent	t_dirent;
typedef struct	stat	t_stat;
typedef struct	s_info
{
	int		st_mode;
	char	st_name[PATH_MAX + 1];
	int		st_nlink;
	int		st_user;
	int		st_group;
	long	st_flags;
	size_t	st_size;
}				t_info;


typedef struct	s_ls
{

}				t_ls;

int				handle_dir(char *name, long opt);

unsigned int	ls_options(char *av);
void			usage(char c);

#endif
