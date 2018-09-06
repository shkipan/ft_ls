/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   messages.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dskrypny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/16 18:27:30 by dskrypny          #+#    #+#             */
/*   Updated: 2018/09/01 20:53:02 by dskrypny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_ls.h"

int			error(t_ls *lst, char *file_name)
{
	t_stat	file_info;

	lst->error = 1;
	lst->printed = 1;
	if (!lstat(file_name, &file_info))
		ft_printf("ft_ls: %s: Permission denied\n", file_name);
	else
		ft_printf("ft_ls: %s: No such file or directory\n", file_name);
	return (1);
}

void		usage(char c)
{
	ft_printf("ft_ls: illegal option -- %c\n", c);
	ft_printf("usage: ./ft_ls [%s] [file ...]\n", SUPPORTED);
	exit(1);
}
