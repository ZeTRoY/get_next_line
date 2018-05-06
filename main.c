/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroi <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/17 16:42:37 by aroi              #+#    #+#             */
/*   Updated: 2018/05/06 13:13:09 by aroi             ###   ########.fr       */
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
	char	*line;

	i = 0;
	if (argc > 1)
		while (++i < argc)
		{
			fd = open(argv[i], O_RDONLY);
			while ((cd = get_next_line(fd, &line)) > 0)
				printf("%s\n", line);
			printf("Here's a line: %s and cd: %i\n", line, cd);
		}
	return (0);
}
