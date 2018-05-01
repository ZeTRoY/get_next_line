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
#include "fcntl.h"

int		qnt_end(char buff[BUFF_SIZE], size_t size)
{
	int		qnt;
	size_t	i;

	i = 0;
	qnt = 0;
	while (i < size)
		if (buff[i++] == '\n')
			qnt++;
	return (qnt);
}

int		get_next_line(int fd, char **line)
{
	int			i;
	int			j;
	int			rd;
	char		*str;
	static char	buff[BUFF_SIZE + 1];

	i = 0;
	j = 0;
	if (line && *line)
		ft_bzero((void *)*line, ft_strlen(*line));
	if (!buff[0])
	{
		if ((rd = read(fd, buff, BUFF_SIZE)) == -1)
			return (-1);
		buff[BUFF_SIZE] = '\0';
	}
	while (!qnt_end(buff, BUFF_SIZE))
	{
		if (!line || !*line)
			*line = ft_strdup((char *)buff);
		else
			*line = ft_strjoin(*line, (char *)buff);
		if ((rd = read(fd, buff, BUFF_SIZE)) == -1)
			return (-1);
		buff[BUFF_SIZE] = '\0';
	}
	printf("%s\n", buff);
	if (rd == 0)
		return (0);
	else if (rd == 1)
		return (1);
	else
		return (-1);
}
