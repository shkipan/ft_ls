/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_format.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dskrypny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/15 18:50:37 by dskrypny          #+#    #+#             */
/*   Updated: 2018/06/15 22:49:14 by dskrypny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int		ft_zero_format(t_format **prop)
{
	if ((*prop)->width != 0)
		return (0);
	if ((*prop)->prec != 0)
		return (0);
	if ((*prop)->dot != 0)
		return (0);
	if ((*prop)->plus != 0)
		return (0);
	if ((*prop)->minus != 0)
		return (0);
	if ((*prop)->hash != 0)
		return (0);
	if ((*prop)->zero != 0)
		return (0);
	if ((*prop)->space != 0)
		return (0);
	if ((*prop)->color != 0)
		return (0);
	if ((*prop)->s_mod != 0)
		return (0);
	return (1);
}
