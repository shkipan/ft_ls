/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   messages.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dskrypny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/16 18:27:30 by dskrypny          #+#    #+#             */
/*   Updated: 2018/08/16 21:28:35 by dskrypny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_ls.h"

void		error(int c, char *file_name)
{
	if (c == 1)
		ft_printf("ft_ls: %s: No such file or directory\n", file_name);
}

void		usage(char c)
{
	ft_printf("ft_ls: illegal option -- %c\n", c);
	ft_printf("usage: ./ft_ls [%s] [file ...]\n", SUPPORTED);
	exit(1);
}
