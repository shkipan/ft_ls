/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dskrypny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/25 16:39:53 by dskrypny          #+#    #+#             */
/*   Updated: 2018/08/09 21:04:42 by dskrypny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_ls.h"

void	usage(char c)
{
	ft_printf("ft_ls: illegal option -- %c\n", c);
	ft_printf("usage: ./ft_ls [%s] [file ...]\n", SUPPORTED);
//	system("leaks ft_ls");
	exit(1);
}

int		main(int ac, char **av)
{
	int				i;
	unsigned int	opt;
	
	i = 0; 
	opt = 0;
	while (++i < ac && av[i][0] == '-')
		opt |= (av[i][0] == '-') ? ls_options(av[i]) : 0;
	if (ac == 1 || i == ac)
		handle_dir(".", opt);
	else
	{
		while (i < ac)
		{
			if (handle_dir(av[i], opt))
				continue ;
			i++;
		}
	}
//	system("leaks ft_ls");
	return (0);
}
