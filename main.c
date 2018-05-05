/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroi <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/17 16:42:37 by aroi              #+#    #+#             */
/*   Updated: 2018/05/01 15:04:24 by aroi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "get_next_line.h"

#include <stdio.h>
#include <fcntl.h>

int		get_next_line(int fd, char **line);

int		main(int argc, char **argv)
{
	int		cd;
	int		fd;
	int		i;
	char	*line;

	i = 0;
	if (argc > 1)
		while (++i < argc)
		{
			fd = open(argv[i], O_RDONLY);
			while ((cd = get_next_line(fd, &line)) > 0)
				printf("Here's a line: %s and cd: %i\n", line, cd);
	//			printf(":)\n");
	//		printf("Here's a line: %s and cd: %i\n", line, cd);
		}
//	system("leaks a.out");
	return (0);
}
