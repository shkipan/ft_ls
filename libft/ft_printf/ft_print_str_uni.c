/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dskrypny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/17 18:58:42 by dskrypny          #+#    #+#             */
/*   Updated: 2018/07/03 16:56:30 by dskrypny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	spin_str_uni(wchar_t *s, char *t, size_t needed)
{
	int		i;
	size_t	size;
	char	*temp;

	ft_putstr(t);
	i = -1;
	size = 0;
	while (needed && s[++i])
	{
		if ((int)s[i] < 128)
		{
			if ((size + 1) > needed)
				return ;
			write(1, &(s[i]), 1);
			size++;
			continue ;
		}
		temp = ft_itoa_base((int)s[i], 2);
		if ((size + select_size(ft_strlen(temp))) > needed)
			return ;
		create_uni(temp, (int)s[i]);
		size += select_size(ft_strlen(temp));
		free(temp);
	}
}

size_t	select_uni(t_format **prop, wchar_t *s)
{
	int		i;
	size_t	size;
	size_t	needed;
	char	*temp;

	size = 0;
	i = -1;
	if (!(*prop)->prec && (*prop)->dot)
		return (0);
	needed = ((*prop)->prec) ? (*prop)->prec : 0;
	while (s[++i])
	{
		temp = ft_itoa_base(s[i], 2);
		if (needed && (size + select_size(ft_strlen(temp))) > (*prop)->prec)
			break ;
		size += select_size(ft_strlen(temp));
		free(temp);
	}
	return (size);
}

char	*create_zero_uni(t_format **p)
{
	size_t	needed;
	char	*temp;
	char	*res;

	res = ft_strdup("");
	needed = ((*p)->zero && (*p)->dot && !(*p)->prec) ? 1 : 0;
	if (needed)
		needed = (*p)->width;
	while (ft_strlen(res) < needed)
	{
		temp = res;
		res = ft_strjoin(res, "0");
		free(temp);
	}
	return (res);
}

int		ft_print_str_uni(t_format **prop, va_list argument)
{
	wchar_t	*s;
	char	*f;
	char	*t;
	size_t	size;

	size = 0;
	s = va_arg(argument, wchar_t *);
	if (s == 0)
		s = L"(null)";
	size = select_uni(prop, s);
	t = create_zero_uni(prop);
	size += ft_strlen(t);
	f = fill_str_str(prop, size);
	size -= ft_strlen(t);
	(*prop)->minus == 0 ? ft_putstr(f) : spin_str_uni(s, t, size);
	(*prop)->minus == 1 ? ft_putstr(f) : spin_str_uni(s, t, size);
	size += ft_strlen(f) + ft_strlen(t);
	free(f);
	free(t);
	(*prop)->is_printed = 1;
	return (size);
}
