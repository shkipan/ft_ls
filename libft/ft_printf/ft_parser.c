/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dskrypny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/19 19:24:38 by dskrypny          #+#    #+#             */
/*   Updated: 2018/07/03 16:09:59 by dskrypny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	wildcard(va_list argument, t_format **formating, int flag)
{
	int	x;

	x = va_arg(argument, int);
	if (x < 0 && flag == 1)
		(*formating)->minus = 1;
	if (flag == 1)
		(*formating)->width = ABS(x);
	else
	{
		(*formating)->prec = (x <= 0) ? 0 : x;
		(*formating)->dot = 1;
	}
}

int		is_supp(char c)
{
	int i;

	i = 0;
	while (EX[i])
	{
		if (EX[i] == c || ft_isdigit(c))
			return (1);
		i++;
	}
	return (0);
}

int		skip_num(char *s, t_format **formating, char c)
{
	int k;

	k = 0;
	if (c == '{')
		return (ft_print_color(formating, s));
	if (c == '.')
		(*formating)->dot = 1;
	if (c != '.')
		(*formating)->width = ft_atoi(s);
	else
		(*formating)->prec = ft_atoi(s);
	while (ft_isdigit(*s))
	{
		s++;
		k++;
	}
	return (k - 1);
}

void	ft_parser_2(t_format **formating, char *start, int pos,
		va_list argument)
{
	if (*(start + pos) == '-')
		(*formating)->minus = 1;
	else if (*(start + pos) == '*' && (*(start + pos - 1) != '.'))
		wildcard(argument, formating, 1);
	else if (*(start + pos) == '.')
		(*formating)->dot = 1;
	else if (*(start + pos) == '+')
		(*formating)->plus = 1;
	else if (*(start + pos) == '#')
		(*formating)->hash = 1;
	else if (*(start + pos) == ' ')
		(*formating)->space = 1;
	else if (*(start + pos) == 'l')
		(*formating)->s_mod = ((*formating)->s_mod == 3) ? 4 : 3;
	else if (*(start + pos) == 'h')
		(*formating)->s_mod = ((*formating)->s_mod == 2) ? 1 : 2;
	else if (*(start + pos) == 'j')
		(*formating)->s_mod = 5;
	else if (*(start + pos) == 'z')
		(*formating)->s_mod = 6;
}

int		ft_parser(t_format **formating, size_t *index, char *format,
		va_list argument)
{
	char		*start;
	int			pos;

	pos = -1;
	start = format + *index + 1;
	while (*(start + pos) && is_supp(*(start + ++pos)))
	{
		if (*(start + pos) == '0' && *(start + pos - 1) != '.')
			(*formating)->zero = 1;
		else if (ft_isdigit(*(start + pos)))
			pos += skip_num(start + pos, formating, *(start + pos - 1));
		else if (*(start + pos) == '{')
			pos += skip_num(start + pos + 1, formating, *(start + pos));
		else if (*(start + pos) == '*' && (*(start + pos - 1) == '.'))
			wildcard(argument, formating, 0);
		ft_parser_2(formating, start, pos, argument);
	}
	return (pos + 1);
}
