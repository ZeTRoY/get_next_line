/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroi <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/17 16:42:37 by aroi              #+#    #+#             */
/*   Updated: 2018/05/19 13:27:53 by aroi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "get_next_line.h"

#include <stdio.h>
#include <fcntl.h>

int		main(int argc, char **argv)
{
	int		cd;
	int		fd;
	int		i;
	int		j;
	char	*line;
	/*
	i = 0;
	j = 0;
	if (argc > 1)
		while (++i < argc)
		{
			fd = open(argv[i], O_RDONLY);
			while (++j < 5)
			{
				while ((cd = get_next_line(fd, &line)) > 0)
					printf("%d | %s\n", cd, line);
				printf("Here's a line: %s and cd: %i\n", line, cd);
			}
		}
		*/

	i = -1;
	int fd1 = open("large_file.txt", O_RDONLY);
	// int fd2	= open("file2", O_RDONLY);
	// int fd3 = open("file3", O_RDONLY);
	while (++i < 800)
	{
		cd = get_next_line(fd1, &line);
		printf("%d | %d | %s\n", i, cd, line);
		// cd = get_next_line(fd2, &line);
		// printf("%d | %s\n", cd, line);
		// cd = get_next_line(fd3, &line);
		// printf("%d | %s\n", cd, line);
	}
	return (0);
}
