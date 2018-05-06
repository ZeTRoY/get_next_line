/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroi <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/06 12:08:18 by aroi              #+#    #+#             */
/*   Updated: 2018/05/06 14:14:03 by aroi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "get_next_line.h"

static t_line	*ft_newlist(char *str, int fd)
{
	t_line *list;

	list = (t_line *)malloc(sizeof(t_line));
	if (!list)
		return (0);
	list->content = (char *)malloc(sizeof(char) * (ft_strlen(str) + 1));
	if (!list->content)
	{
		free(list);
		return (0);
	}
	list->fd = fd;
	ft_strcpy(list->content, str);
	list->next = 0;
	return (list);
}

static t_line	*ft_add_and_find_elem(int fd, t_line **list)
{
	char	*str;
	t_line	*tmp;

	if (!*list)
	{
		str = ft_strdup("");
		*list = ft_newlist(str, fd);
		ft_strdel(&str);
		return (*list);
	}
	tmp = *list;
	while (tmp->next)
	{
		if (tmp->fd == fd)
			return (tmp);
		tmp = tmp->next;
	}
	if (tmp->fd == fd)
		return (tmp);
	str = ft_strdup("");
	tmp->next = ft_newlist(str, fd);
	ft_strdel(&str);
	return (tmp->next);
}

static int		ft_read_until_end(int res, char **line,
		char **buff, t_line **tmp_list)
{
	char	*str;
	t_line	*tmp;

	tmp = *tmp_list;
	if (res == 0 && !ft_strcmp(tmp->content, ""))
	{
		ft_strdel(buff);
		return (0);
	}
	else if (res == 0)
	{
		*line = ft_strjoin(tmp->content, *buff);
		tmp->content = "";
		ft_strdel(buff);
		return (1);
	}
	str = tmp->content;
	tmp->content = ft_strjoin(tmp->content, *buff);
	ft_strdel(&str);
	return (-1);
}

static void		ft_del_and_add_line(char **line, char **buff, char **cont)
{
	char *str;

	*line = ft_strsub(*cont, 0, ft_strchr(*cont, '\n') - *cont);
	str = *cont;
	*cont = ft_strsub(*cont, ft_strchr(*cont, '\n') - *cont + 1,
			ft_strlen(*cont) - (ft_strchr(*cont, '\n') - *cont) - 1);
	ft_strdel(&str);
	ft_strdel(buff);
}

int				get_next_line(int fd, char **line)
{
	int				res;
	char			*buff;
	static t_line	*list;
	t_line			*tmp;

	buff = (char *)malloc(BUFF_SIZE + 1);
	if (fd < 0 || !buff || read(fd, buff, 0) == -1)
	{
		ft_strdel(&buff);
		return (-1);
	}
	tmp = ft_add_and_find_elem(fd, &list);
	while (!ft_strchr(tmp->content, '\n'))
	{
		ft_bzero(buff, BUFF_SIZE + 1);
		res = read(fd, buff, BUFF_SIZE);
		if ((res = ft_read_until_end(res, line, &buff, &tmp)) >= 0)
			return (res);
	}
	ft_del_and_add_line(line, &buff, (char **)&tmp->content);
	return (1);
}
