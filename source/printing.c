/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dskrypny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/20 13:31:39 by dskrypny          #+#    #+#             */
/*   Updated: 2018/08/23 17:58:19 by dskrypny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_ls.h"

static void		edit_name(t_ls *lst, t_info *tmp)
{
	char	*del;

	if (!CHECK_FLAG(lst->opt, 'p'))
		return ;
	if (tmp->st_mode[0] == 'd')
	{
		del = tmp->st_name;
		tmp->st_name = ft_strjoin(tmp->st_name, "/");
		free(del);
	}
}

static void		l_stuff(t_ls *lst, t_info *tmp)
{
	if (!CHECK_FLAG(lst->opt, 'g'))
		(CHECK_FLAG(lst->opt, 'n')) ?
			ft_printf("%-*d  ", lst->user_width, tmp->st_uid) :
			ft_printf("%-*s  ", lst->user_width, tmp->st_user);
	if (!CHECK_FLAG(lst->opt, 'o'))
		(CHECK_FLAG(lst->opt, 'n')) ?
			ft_printf("%-*d  ", lst->group_width, tmp->st_gid) :
			ft_printf("%-*s  ", lst->group_width, tmp->st_group);
	ft_printf("%*d ", lst->size_width, tmp->st_size);
	edit_name(lst, tmp);
	ft_printf("%s %s\n", tmp->st_time, tmp->st_name);
	if (CHECK_BIT(lst->opt, 27) && tmp->xattr_length > 0)
		ft_printf("\t%s %d\n", tmp->xattr, tmp->xattr_length);
}

int				print_l(t_ls *lst)
{
	t_info		*tmp;

	tmp = lst->files;
	while (tmp)
	{
		ft_printf("%s ", tmp->st_mode);
		ft_printf("%*d ", lst->nlink_width, tmp->st_nlink);
		l_stuff(lst, tmp);
		tmp = tmp->next;
	}
	if (CHECK_BIT(lst->opt, 28))
		print_recursive(lst);
	return (0);
}

int				print_m(t_ls *lst)
{
	t_info		*tmp;
	size_t		k;
	char		*delim;

	k = 0;
	tmp = lst->files;
	while (tmp)
	{
		if (k + ft_strlen(tmp->st_name) + ((tmp->next) ? 2 : 1)
				> lst->win_param.ws_col)
		{
			ft_printf("\n");
			k = 0;
		}
		delim = (tmp->next) ? ", " : "\n";
		edit_name(lst, tmp);
		ft_printf("%s%s", tmp->st_name, delim);
		k += ft_strlen(tmp->st_name) + ft_strlen(delim);
		tmp = tmp->next;
	}
	if (CHECK_BIT(lst->opt, 28))
		print_recursive(lst);
	return (0);
}

int				print_x(t_ls *lst)
{
	t_info		*tmp;
	size_t		k;
	char		*delim;

	k = 0;
	tmp = lst->files;
	while (tmp)
	{
		if (k + lst->tab_width + ((tmp->next) ? 1 : 0)
				> lst->win_param.ws_col)
		{
			ft_printf("\n");
			k = 0;
		}
		edit_name(lst, tmp);
		delim = (tmp->next) ? "" : "\n";
		ft_printf("%-*s%s", lst->tab_width, tmp->st_name, delim);
		k += lst->tab_width;
		tmp = tmp->next;
	}
	if (CHECK_BIT(lst->opt, 28))
		print_recursive(lst);
	return (0);
}
