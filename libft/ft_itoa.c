/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroi <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/25 09:06:56 by aroi              #+#    #+#             */
/*   Updated: 2018/03/26 21:38:43 by aroi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	qnt_counter(int n)
{
	size_t qnt;

	qnt = 0;
	if (n < 0)
		n *= -1;
	while (n > 0)
	{
		n /= 10;
		qnt++;
	}
	return (qnt);
}

static char		*givestr(char *str, size_t i, int n)
{
	int		j;
	int		nbr[qnt_counter(n)];

	j = 0;
	while (n > 0)
	{
		nbr[j++] = n % 10;
		n /= 10;
	}
	while (n < 0)
	{
		nbr[j] = n % 10;
		nbr[j++] *= -1;
		n /= 10;
	}
	while (j >= 0)
		str[i++] = (char)nbr[--j] + 48;
	return (str);
}

static char		*nbr_exchanger(int n)
{
	char	*str;

	if (n > 0)
	{
		str = (char *)malloc(sizeof(char) * (qnt_counter(n) + 1));
		if (str)
		{
			str = givestr(str, 0, n);
			str[qnt_counter(n)] = '\0';
			return (str);
		}
	}
	else
	{
		str = (char *)malloc(sizeof(char) * (qnt_counter(n) + 2));
		if (str)
		{
			str[0] = '-';
			str = givestr(str, 1, n);
			str[qnt_counter(n) + 1] = '\0';
			return (str);
		}
	}
	return (0);
}

static char		*min_int(int n)
{
	int		i;
	int		j;
	int		nbr[10];
	char	*str;

	i = 0;
	j = 0;
	str = (char *)malloc(sizeof(char) * 12);
	if (str)
	{
		str[0] = '-';
		while (n < 0)
		{
			nbr[i++] = (n % 10) * (-1);
			n /= 10;
		}
		while (--i >= 0)
			str[1 + j++] = nbr[i] + 48;
		str[11] = '\0';
		return (str);
	}
	return (0);
}

char			*ft_itoa(int n)
{
	char	*str;

	str = 0;
	if (n == -2147483648)
		return (min_int(n));
	else if (n == 0)
	{
		str = (char *)malloc(sizeof(char) * 2);
		if (str)
		{
			str[0] = '0';
			str[1] = '\0';
			return (str);
		}
	}
	else if (n > 0 || n < 0)
		return (nbr_exchanger(n));
	return (str);
}
