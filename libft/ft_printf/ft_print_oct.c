/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_oct.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dskrypny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/17 18:58:42 by dskrypny          #+#    #+#             */
/*   Updated: 2018/07/03 15:33:47 by dskrypny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*fill_str_oct(t_format **prop, size_t length)
{
	char	*res;
	char	*temp;
	size_t	i;
	size_t	size;

	if ((*prop)->width == 0 || length > (*prop)->width ||
			ft_zero_format(prop))
		return (ft_strnew(0));
	size = (*prop)->width - length;
	res = ft_strnew(0);
	i = 0;
	while (i < size)
	{
		temp = res;
		res = ft_strjoin(res, " ");
		free(temp);
		i++;
	}
	res[i] = '\0';
	return (res);
}

char	*create_oct(t_format **prop, size_t c)
{
	char	*temp;
	char	*s;
	size_t	size;
	size_t	needed;

	s = (c == 0 && !(*prop)->prec && (*prop)->dot) ? ft_strnew(0) :
		ft_itoa_base_printf(c, 8);
	size = ft_strlen(s) - 1;
	needed = ((*prop)->prec || (*prop)->width) ? 1 : 0;
	if (needed)
		needed = ((*prop)->prec) ? (*prop)->prec :
			(*prop)->zero * ((*prop)->width - (*prop)->space);
	if ((*prop)->hash && ft_strcmp(s, "0"))
	{
		temp = s;
		s = ft_strjoin("0", s);
		free(temp);
	}
	while (ft_strlen(s) < needed)
	{
		temp = s;
		s = ft_strjoin("0", s);
		free(temp);
	}
	return (s);
}

int		ft_print_oct(t_format **prop, va_list argument)
{
	char			*s;
	char			*f;
	size_t			size;
	size_t			c;

	(*prop)->zero = ((*prop)->minus) ? 0 : (*prop)->zero;
	c = ft_find_arg(prop, argument);
	s = create_oct(prop, c);
	size = ft_strlen(s);
	f = fill_str_oct(prop, size);
	size += ft_strlen(f);
	(*prop)->minus == 0 ? ft_putstr(f) : ft_putstr(s);
	(*prop)->minus == 1 ? ft_putstr(f) : ft_putstr(s);
	free(f);
	if (ft_strcmp(s, ""))
		free(s);
	(*prop)->is_printed = 1;
	return (size);
}
