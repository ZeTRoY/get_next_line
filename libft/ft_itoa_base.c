/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroi <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/28 19:25:16 by aroi              #+#    #+#             */
/*   Updated: 2018/03/28 21:02:04 by aroi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*itoc(int n, int base, int qnt)
{
	char *str;

	if (n == 0)
	{
		str = (char *)malloc(sizeof(char) * 2);
		str[0] = '0';
		str[1] = '\0';
		return (str);
	}
	str = (char *)malloc(sizeof(char) * (qnt + 1));
	if (str == 0)
		return (0);
	str[qnt] = '\0';
	if (n < 0)
		n *= -1;
	while (--qnt >= 0)
	{
		if (n % base < 10)
			str[qnt] = n % base + 48;
		else
			str[qnt] = n % base + 55;
		n /= base;
	}
	return (str);
}

static char	*min_int(int n, int base, int qnt)
{
	char *minint;

	minint = (char *)malloc(sizeof(char) * (qnt + 1));
	if (minint == 0)
		return (0);
	minint[qnt] = '\0';
	while (--qnt >= 0)
	{
		if (n % base > -10)
			minint[qnt] = -(n % base) + 48;
		else
			minint[qnt] = -(n % base) + 55;
		n /= base;
	}
	return (minint);
}

char		*ft_itoa_base(int n, int base)
{
	int k;
	int qnt;

	if (base == 10)
		return (ft_itoa(n));
	if ((base < 2 || base > 16) && n != 0)
		return ("Enter base from 2 to 16, please.");
	k = n;
	qnt = 0;
	while (k != 0)
	{
		qnt++;
		k /= base;
	}
	if (n == -2147483648)
		return (min_int(n, base, qnt));
	return (itoc(n, base, qnt));
}
