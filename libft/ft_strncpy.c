/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroi <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 16:00:45 by aroi              #+#    #+#             */
/*   Updated: 2018/03/26 21:07:49 by aroi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	int i;
	int j;

	i = -1;
	j = 0;
	while (++i < (int)len && src[i])
		dst[i] = src[i];
	if (src[i] == '\0')
	{
		while (i < (int)len)
			dst[i++] = '\0';
	}
	return (dst);
}
