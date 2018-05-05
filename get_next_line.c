/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroi <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/17 16:47:45 by aroi              #+#    #+#             */
/*   Updated: 2018/05/05 20:24:43 by aroi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "get_next_line.h"

static t_list	*ft_add_elem(int fd, t_list **list)
{
	char	*str;
	t_list	*tmp;

	if (!list || !*list)
	{
		str = ft_strdup("");
		*list = ft_lstnew(str, 1);
		ft_strdel(&str);
		return (*list);
	}
	tmp = *list;
	if (!tmp->next)
	{
		str = ft_strdup("");
		tmp->next = ft_lstnew(str, 1);
		ft_strdel(&str);
	}
	else
		while (tmp->next)
			tmp = tmp->next;
	return (tmp);
}

static int		ft_read_until_end(char **line, char **buff, t_list **list_buff)
{
	char	*str;
	t_list	*tmp;

	tmp = *list_buff;
	if ((*buff)[0] == '\0' && ((char *)tmp->content)[0] == '\0')
	{
		ft_strdel(buff);
		return (0);
	}
	ft_strdel(line);
	*line = ft_strjoin(tmp->content, *buff);
	str = ft_strdup("");
	tmp->next = ft_lstnew(str, 1);
	ft_strdel(&str);
	ft_strdel(buff);
	return (1);
}

static void		ft_del_and_add_line(char **line, char **buff, char **lst_cont)
{
	char *str;

	ft_strdel(line);
	*line = ft_strsub(*lst_cont, 0, ft_strchr(*lst_cont, '\n') - *lst_cont);
	str = *lst_cont;
	*lst_cont = ft_strsub(*lst_cont, ft_strchr(*lst_cont, '\n') - *lst_cont + 1,
		ft_strlen(*lst_cont) - (ft_strchr(*lst_cont, '\n') - *lst_cont) - 1);
	ft_strdel(&str);
	ft_strdel(buff);
}

int				get_next_line(int fd, char **line)
{
	char			*buff;
	char			*str;
	static t_list	*list;
	t_list			*list_buff;

	buff = (char *)malloc(BUFF_SIZE + 1);
	if (fd < 0 || !buff || read(fd, buff, 0) == -1)
	{
		ft_strdel(&buff);
		return (-1);
	}
	list_buff = ft_add_elem(fd, &list);
	while (!ft_strchr(list_buff->content, '\n'))
	{
		ft_bzero(buff, BUFF_SIZE + 1);
		read(fd, buff, BUFF_SIZE);
		if (buff[0] == '\0')
			return (ft_read_until_end(line, &buff, &list_buff));
		str = list_buff->content;
		list_buff->content = ft_strjoin(list_buff->content, buff);
		ft_strdel(&str);
	}
	ft_del_and_add_line(line, &buff, (char **)&list_buff->content);
	return (1);
}
