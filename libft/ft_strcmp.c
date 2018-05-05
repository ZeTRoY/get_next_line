/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroi <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 20:59:12 by aroi              #+#    #+#             */
/*   Updated: 2018/03/26 18:58:37 by aroi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strcmp(const char *s1, const char *s2)
{
	int i;

	i = 0;
	while (s1[i] != '\0' && s2[i] != '\0')
	{
		if ((unsigned char)s1[i] != (unsigned char)s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	if ((s1[i] != '\0' && s2[i] == '\0') || (s1[i] == '\0' && s2[i] != '\0'))
		return ((unsigned char)s1[i] - (unsigned char)s2[i]);
	else
	{
		if (s1 == 0)
			return ((unsigned char)s2[0] * (-1));
		else if (s2 == 0)
			return ((unsigned char)s1[0]);
	}
	return (0);
}
