/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_sym.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dskrypny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/12 19:49:25 by dskrypny          #+#    #+#             */
/*   Updated: 2018/06/29 11:07:28 by dskrypny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*fill_str_chr(t_format **prop, size_t size)
{
	char	*res;
	char	*temp;
	size_t	i;

	if (size == 0)
		return (ft_strnew(0));
	res = ft_strnew(0);
	i = -1;
	while (++i < size)
	{
		temp = res;
		res = ((*prop)->zero) ? ft_strjoin("0", res) : ft_strjoin(" ", res);
		free(temp);
	}
	return (res);
}

int		ft_print_chr(t_format **prop, va_list argument)
{
	int		ch;
	char	*f;
	int		size;

	(*prop)->zero = ((*prop)->minus) ? 0 : (*prop)->zero;
	ch = va_arg(argument, int);
	f = fill_str_chr(prop, ((*prop)->width) ? (*prop)->width - 1 : 0);
	size = ft_strlen(f);
	(*prop)->minus == 0 ? ft_putstr(f) : ft_putchar(ch);
	(*prop)->minus == 1 ? ft_putstr(f) : ft_putchar(ch);
	free(f);
	(*prop)->is_printed = 1;
	return (size + 1);
}
