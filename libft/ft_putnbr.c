/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroi <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/25 10:13:00 by aroi              #+#    #+#             */
/*   Updated: 2018/03/25 10:42:52 by aroi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	qnt_counter(int n)
{
	int qnt;

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

void		ft_putnbr(int n)
{
	int	i;
	int	nbr[qnt_counter(n)];

	i = 0;
	if (n < 0)
	{
		ft_putchar('-');
		if (n == -2147483648)
			ft_putstr("2147483648");
		n *= -1;
	}
	if (n == 0)
		ft_putchar('0');
	while (n > 0)
	{
		nbr[i++] = n % 10;
		n /= 10;
	}
	while (--i >= 0)
		ft_putchar((char)nbr[i] + 48);
}
