/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_slash.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dskrypny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/27 19:25:04 by dskrypny          #+#    #+#             */
/*   Updated: 2018/09/11 11:11:17 by dskrypny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_ls.h"

size_t		newline(void)
{
	ft_printf("\n");
	return (0);
}

void		edit_name(t_ls *lst, t_info *tmp)
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

char		*select_end(t_ls *lst, t_info *tmp)
{
	if (tmp->st_mode[0] == 'd' && (CHECK_FLAG(lst->opt, 'p') ||
				CHECK_BIT(lst->opt, 29)))
		return ("/");
	else if (CHECK_BIT(lst->opt, 29) && tmp->st_mode[0] != 'd' &&
			(tmp->st_mode[3] == 'x' || tmp->st_mode[6] == 'x' ||
			tmp->st_mode[9] == 'x'))
		return ("*");
	return ("");
}

void		print_name(t_ls *lst, t_info *tmp)
{
	if (CHECK_BIT(lst->opt, 30) && tmp->st_mode[0] == 'd')
		ft_printf("%{blu}s", tmp->st_name);
	else if (CHECK_BIT(lst->opt, 30) && tmp->st_mode[0] != 'd' &&
			(tmp->st_mode[3] == 'x' || tmp->st_mode[6] == 'x' ||
			tmp->st_mode[9] == 'x'))
		ft_printf("\e[47m\e[34m%s\e[49m\e[39m", tmp->st_name);
	else if (CHECK_BIT(lst->opt, 30) && tmp->st_mode[0] == 'd' &&
			(tmp->chmod[0] == 7 && tmp->chmod[1] == 7
			&& tmp->chmod[2] == 7))
		ft_printf("\e[43m\e[30m%s\e[49m\e[39m", tmp->st_name);
	else
		ft_printf("%s", tmp->st_name);
	ft_printf(" |%d %d|", tmp->dev[0], tmp->dev[1]);
	ft_printf("%s", select_end(lst, tmp));
}
