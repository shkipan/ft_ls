/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_num.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dskrypny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/17 18:58:42 by dskrypny          #+#    #+#             */
/*   Updated: 2018/07/25 13:09:41 by dskrypny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char			*fill_str_num(t_format **prop, size_t length)
{
	char	*res;
	char	*temp;
	size_t	i;
	size_t	size;

	if ((*prop)->width == 0 || length >= (*prop)->width ||
			ft_zero_format(prop))
		return (ft_strdup(""));
	size = (*prop)->width - length;
	res = ft_strdup("");
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

void			figure_sign(t_format **prop, char **s, long long int c)
{
	char	*temp;

	if ((*prop)->plus && !(((*s)[0] == '-') || ((*s)[0] == '+')))
	{
		temp = *s;
		*s = (c < 0) ? ft_strjoin("-", *s) : ft_strjoin("+", *s);
		free(temp);
	}
	if ((*prop)->space && !(*s[0] == '-' || *s[0] == '+'))
	{
		temp = *s;
		*s = ft_strjoin(" ", *s);
		free(temp);
	}
}

char			*create_numb(t_format **p, long long int c)
{
	char	*s;
	char	*temp;
	size_t	size;
	size_t	needed;

	s = (c == 0 && !(*p)->prec && (*p)->dot) ?
		ft_strnew(0) : ft_itoa(ABS(c));
	size = ft_strlen(s) - 1;
	needed = ((*p)->prec || (*p)->width) ? 1 : 0;
	if (needed)
		needed = ((*p)->prec) ? (*p)->prec :
			(*p)->zero * ((*p)->width - (*p)->space - (*p)->plus);
	while (needed > ++size)
	{
		temp = s;
		s = ft_strjoin("0", s);
		free(temp);
	}
	figure_sign(p, &s, c);
	return (s);
}

long long int	ft_find_arg_num(t_format **p, va_list argument)
{
	long long int ret;

	if ((*p)->s_mod == 1)
		ret = (char)va_arg(argument, int);
	else if ((*p)->s_mod == 2)
		ret = (short int)va_arg(argument, int);
	else if ((*p)->s_mod == 3)
		ret = va_arg(argument, long int);
	else if ((*p)->s_mod == 4)
		ret = va_arg(argument, long long int);
	else if ((*p)->s_mod == 5)
		ret = va_arg(argument, intmax_t);
	else if ((*p)->s_mod == 6)
		ret = va_arg(argument, size_t);
	else
		ret = va_arg(argument, int);
	return (ret);
}

int				ft_print_num(t_format **prop, va_list argument)
{
	char			*s;
	char			*f;
	size_t			size;
	long long int	c;

	c = ft_find_arg_num(prop, argument);
	(*prop)->plus = (c < 0) ? 1 : (*prop)->plus;
	(*prop)->space = ((*prop)->plus) ? 0 : (*prop)->space;
	(*prop)->zero = ((*prop)->minus) ? 0 : (*prop)->zero;
	s = create_numb(prop, c);
	size = ft_strlen(s);
	f = fill_str_num(prop, size);
	size += ft_strlen(f);
	(*prop)->minus == 0 ? ft_putstr(f) : ft_putstr(s);
	(*prop)->minus == 1 ? ft_putstr(f) : ft_putstr(s);
	free(s);
	free(f);
	(*prop)->is_printed = 1;
	return (size);
}
