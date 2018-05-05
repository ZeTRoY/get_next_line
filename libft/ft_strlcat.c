/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroi <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 13:58:07 by aroi              #+#    #+#             */
/*   Updated: 2018/03/30 16:05:49 by aroi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	int		i;
	int		j;

	i = -1;
	j = (int)ft_strlen(dst);
	if (dst && src)
	{
		if (size > (size_t)j)
		{
			while (++i < (int)size - j - 1 && src[i])
				dst[j + i] = src[i];
			dst[j + i] = '\0';
			return (ft_strlen(src) + j);
		}
		else
			return (ft_strlen(src) + size);
	}
	return (ft_strlen(src));
}
