/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_num.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dskrypny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/17 18:58:42 by dskrypny          #+#    #+#             */
/*   Updated: 2018/06/27 19:16:29 by dskrypny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*fill_str_uns(t_format **prop, size_t length)
{
	char	*res;
	char	*t;
	size_t	i;
	size_t	size;

	if ((*prop)->width == 0 || length >= (*prop)->width)
		return (ft_strdup(""));
	size = (*prop)->width - length;
	res = ft_strdup("");
	i = 0;
	while (i < size)
	{
		t = res;
		res = ft_strjoin(res, " ");
		free(t);
		i++;
	}
	res[i] = '\0';
	return (res);
}

char	*create_uns(t_format **p, size_t c)
{
	char	*s;
	char	*temp;
	size_t	i;
	size_t	needed;

	s = (c == 0 && (*p)->dot && !(*p)->prec)
			? ft_strnew(0) : ft_itoa_uns(c);
	i = ft_strlen(s) - 1;
	needed = ((*p)->prec || (*p)->width) ? 1 : 0;
	if (needed)
		needed = ((*p)->prec) ? (*p)->prec :
			(*p)->zero * ((*p)->width - (*p)->plus - (*p)->space);
	while (needed > ++i)
	{
		temp = s;
		s = ft_strjoin("0", s);
		free(temp);
	}
	return (s);
}

size_t	ft_find_arg_uns(t_format **p, va_list argument)
{
	size_t ret;

	if ((*p)->s_mod == 1)
		ret = (unsigned char)va_arg(argument, int);
	else if ((*p)->s_mod == 2)
		ret = (unsigned short int)va_arg(argument, int);
	else if ((*p)->s_mod == 3)
		ret = va_arg(argument, unsigned long);
	else if ((*p)->s_mod == 4)
		ret = va_arg(argument, unsigned long long int);
	else if ((*p)->s_mod == 5)
		ret = va_arg(argument, uintmax_t);
	else if ((*p)->s_mod == 6)
		ret = va_arg(argument, size_t);
	else
		ret = va_arg(argument, unsigned int);
	return (ret);
}

int		ft_print_uns(t_format **prop, va_list argument)
{
	char			*s;
	char			*f;
	size_t			size;
	size_t			c;

	(*prop)->zero = ((*prop)->minus) ? 0 : (*prop)->zero;
	c = ft_find_arg_uns(prop, argument);
	s = create_uns(prop, c);
	size = ft_strlen(s);
	f = fill_str_uns(prop, size);
	size += ft_strlen(f);
	(*prop)->minus == 0 ? ft_putstr(f) : ft_putstr(s);
	(*prop)->minus == 1 ? ft_putstr(f) : ft_putstr(s);
	free(s);
	free(f);
	(*prop)->is_printed = 1;
	return (size);
}
