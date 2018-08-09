/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_uni.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dskrypny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/27 19:01:42 by dskrypny          #+#    #+#             */
/*   Updated: 2018/06/29 11:28:49 by dskrypny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int		ft_print_uni(t_format **prop, va_list argument)
{
	size_t	size;
	char	*f;
	char	*s;
	int		c;

	c = va_arg(argument, int);
	s = ft_itoa_base(c, 2);
	size = select_size(ft_strlen(s));
	f = fill_str_chr(prop, ((*prop)->width > size) ? (*prop)->width - size : 0);
	size += ft_strlen(f);
	(*prop)->minus == 0 ? ft_putstr(f) : create_uni(s, c);
	(*prop)->minus == 1 ? ft_putstr(f) : create_uni(s, c);
	free(f);
	free(s);
	(*prop)->is_printed = 1;
	return (size);
}
