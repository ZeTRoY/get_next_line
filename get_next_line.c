/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroi <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/17 16:47:45 by aroi              #+#    #+#             */
/*   Updated: 2018/05/01 16:01:02 by aroi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "get_next_line.h"

#include <stdio.h>

int		get_next_line(int fd, char **line)
{
	char			*buff;
	char			*str;
	static t_list	*lst;
	t_list			*lst_line;

	buff = (char *)malloc(sizeof(char) * (BUFF_SIZE + 1));
	if (fd < 0 || !buff || read(fd, buff, 0) == -1)
		return (-1);
	if (!lst)
	{
		str = ft_strdup("");
		lst = ft_lstnew(str, 1);
		ft_strdel(&str);
		lst_line = lst;
	}
	else
	{
		if (!lst_line->next)
		{
			str = ft_strdup("");
			lst_line->next = ft_lstnew(str, 1);
			ft_strdel(&str);
		}
		else
			lst_line = lst_line->next;
	}
	while (!ft_strchr((char *)lst_line->content, '\n'))
	{
		ft_bzero(buff, BUFF_SIZE + 1);
		read(fd, buff, BUFF_SIZE);
		if (buff[0] == '\0' && !((char*)lst_line->content)[0])
			return (0);
		if (buff[0] == '\0')
		{
			*line = ft_strjoin((char *)lst_line->content, buff);
			lst_line->content = "";
			return (1);
		}
		str = (char *)lst_line->content;
		lst_line->content = ft_strjoin((char *)lst_line->content, buff);
		ft_strdel(&str);
	}
	*line = ft_strsub((char *)lst_line->content, 0, ft_strchr((char *)lst_line->content, '\n') - (char *)lst_line->content);
	str = (char *)lst_line->content;
	lst_line->content = ft_strsub((char *)lst_line->content, ft_strchr((char *)lst_line->content, '\n') - (char *)lst_line->content + 1, ft_strlen((char *)lst_line->content) - (ft_strchr((char *)lst_line->content, '\n') - (char *)lst_line->content) - 1);
	ft_strdel(&str);
	ft_strdel(&buff);
	return (1);
}
