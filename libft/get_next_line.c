/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dskrypny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/15 19:20:37 by dskrypny          #+#    #+#             */
/*   Updated: 2018/08/18 19:17:57 by dskrypny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_gnl	*ft_find_stack(int fd, t_gnl **structure)
{
	t_gnl	**temp;

	temp = structure;
	while (*temp)
	{
		if ((*temp)->fd == fd)
			return (*temp);
		temp = &(*temp)->next;
	}
	if (!(*temp = (t_gnl *)malloc(sizeof(t_gnl))))
		return (NULL);
	(*temp)->stack = ft_strdup("");
	(*temp)->fd = fd;
	(*temp)->next = NULL;
	return (*temp);
}

static int		ft_return(char **line, t_gnl *stack)
{
	char	*x;
	char	*tmp;

	if (!(ft_strcmp(stack->stack, "")))
		return (0);
	if ((x = ft_strchr(stack->stack, '\n')) != NULL)
	{
		*line = ft_strsub(stack->stack, 0, (x - stack->stack));
		tmp = stack->stack;
		stack->stack = ft_strdup(x + 1);
		free(tmp);
		return (1);
	}
	*line = ft_strdup(stack->stack);
	tmp = stack->stack;
	stack->stack = ft_strdup("");
	free(tmp);
	return (1);
}

int				get_next_line(const int fd, char **line)
{
	static t_gnl	*structure = NULL;
	char			buf[BUFF_SIZE + 1];
	int				ret;
	char			*temp;
	t_gnl			*stack;

	if (!line || fd < 0 || BUFF_SIZE < 1)
		return (-1);
	if (*line)
		*line = NULL;
	stack = ft_find_stack(fd, &structure);
	while ((ret = read(fd, buf, BUFF_SIZE)))
	{
		if (ret == -1)
			return (-1);
		buf[ret] = '\0';
		temp = stack->stack;
		stack->stack = ft_strjoin(stack->stack, buf);
		free(temp);
		if (ft_strchr(stack->stack, '\n') != NULL)
			break ;
	}
	return (ft_return(line, stack));
}
