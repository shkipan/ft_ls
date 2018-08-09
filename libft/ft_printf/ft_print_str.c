/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dskrypny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/17 18:58:42 by dskrypny          #+#    #+#             */
/*   Updated: 2018/07/03 17:22:13 by dskrypny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*fill_str_str(t_format **prop, size_t length)
{
	char	*res;
	char	*temp;
	size_t	i;
	size_t	size;

	if ((*prop)->width == 0 || length > (*prop)->width)
		return (ft_strdup(""));
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
	return (res);
}

char	*create_str(t_format **p, char *a)
{
	char	*s;
	char	*temp;
	size_t	needed;

	s = (!(*p)->prec && (*p)->dot) ? ft_strdup("") : ft_strdup(a);
	(*p)->zero = ((*p)->prec > ft_strlen(s)) ? 0 : (*p)->zero;
	needed = ((*p)->width || (*p)->prec) ? 1 : 0;
	if (needed)
		needed = ((*p)->prec) ? (*p)->prec : (*p)->width;
	if (needed && (*p)->prec && needed < ft_strlen(s))
		s[needed] = '\0';
	while ((*p)->zero && needed > ft_strlen(s))
	{
		temp = s;
		s = ft_strjoin("0", s);
		free(temp);
	}
	return (s);
}

int		ft_print_str(t_format **prop, va_list argument)
{
	char	*a;
	char	*s;
	char	*f;
	size_t	size;

	a = va_arg(argument, char *);
	s = create_str(prop, a);
	size = ft_strlen(s);
	f = fill_str_str(prop, size);
	size += ft_strlen(f);
	(*prop)->minus == 0 ? ft_putstr(f) : ft_putstr(s);
	(*prop)->minus == 1 ? ft_putstr(f) : ft_putstr(s);
	free(f);
	free(s);
	(*prop)->is_printed = 1;
	return (size);
}
