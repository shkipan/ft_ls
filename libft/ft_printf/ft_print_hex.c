/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dskrypny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/17 18:58:42 by dskrypny          #+#    #+#             */
/*   Updated: 2018/06/28 20:14:11 by dskrypny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*fill_str_hex(t_format **prop, size_t length)
{
	char	*res;
	char	*temp;
	size_t	i;
	size_t	size;

	if ((*prop)->width == 0 || length > (*prop)->width)
		return (ft_strdup(""));
	size = (*prop)->width - length;
	res = ft_strdup("");
	i = -1;
	while (++i < size)
	{
		temp = res;
		res = ft_strjoin(res, " ");
		free(temp);
	}
	return (res);
}

void	figure_hex(t_format **prop, char **s, size_t c)
{
	char	*temp;

	if ((*prop)->hash && c != 0)
	{
		temp = *s;
		*s = ft_strjoin("0x", *s);
		free(temp);
	}
	if ((*prop)->type == 'X')
		ft_strcapit(*s);
}

char	*create_hex(t_format **prop, size_t c)
{
	char	*s;
	char	*temp;
	size_t	needed;

	s = (c == 0 && (*prop)->dot && !((*prop)->prec)) ?
		ft_strdup("") : ft_itoa_base_printf(c, 16);
	(*prop)->width = (!(*prop)->prec && (*prop)->width < 2) ?
		ft_strlen(s) : (*prop)->width;
	needed = (ft_strcmp(s, "")) ? 1 : 0;
	if (needed && ((*prop)->prec || (*prop)->width > 1))
		needed = ((*prop)->prec) ? (*prop)->prec :
			((*prop)->width - 2 * (*prop)->hash) * (*prop)->zero;
	while (needed && ft_strlen(s) < needed)
	{
		temp = s;
		s = ft_strjoin("0", s);
		free(temp);
	}
	figure_hex(prop, &s, c);
	return (s);
}

int		ft_print_hex(t_format **prop, va_list argument)
{
	char			*s;
	char			*f;
	size_t			size;
	size_t			c;

	c = ft_find_arg(prop, argument);
	(*prop)->zero = ((*prop)->minus) ? 0 : (*prop)->zero;
	(*prop)->hash = (c == 0) ? 0 : (*prop)->hash;
	s = create_hex(prop, c);
	size = ft_strlen(s);
	f = fill_str_hex(prop, size);
	size += ft_strlen(f);
	(*prop)->minus == 0 ? ft_putstr(f) : ft_putstr(s);
	(*prop)->minus == 1 ? ft_putstr(f) : ft_putstr(s);
	free(f);
	free(s);
	(*prop)->is_printed = 1;
	return (size);
}
