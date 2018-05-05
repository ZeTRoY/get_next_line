/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroi <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/24 18:32:21 by aroi              #+#    #+#             */
/*   Updated: 2018/03/27 20:28:59 by aroi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char static	*alloc_good(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	char			*str;

	i = 0;
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (str)
	{
		while ((size_t)i < len)
		{
			str[i] = s[start + i];
			i++;
		}
		str[i] = '\0';
		return (str);
	}
	str = 0;
	return (str);
}

char static	*alloc_bad(char const *s, unsigned int start)
{
	unsigned int	i;
	char			*str;

	i = 0;
	str = (char *)malloc(sizeof(char) * (ft_strlen(s) - (size_t)start + 1));
	if (str)
	{
		while (start + i < (unsigned int)ft_strlen(s))
		{
			str[i] = s[start + i];
			i++;
		}
		str[i] = '\0';
		return (str);
	}
	str = 0;
	return (str);
}

char		*ft_strsub(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;

	i = 0;
	if (s && (int)start >= 0 && (int)len >= 0 &&
			(int)ft_strlen(s) - (int)start >= 0)
	{
		if (len < ft_strlen(s) - (size_t)start)
			return (alloc_good(s, start, len));
		else
			return (alloc_bad(s, start));
	}
	return (0);
}
