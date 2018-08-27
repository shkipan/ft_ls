/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_slash.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dskrypny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/27 19:25:04 by dskrypny          #+#    #+#             */
/*   Updated: 2018/08/27 19:30:43 by dskrypny         ###   ########.fr       */
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
