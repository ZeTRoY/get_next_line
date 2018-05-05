/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroi <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/25 10:34:16 by aroi              #+#    #+#             */
/*   Updated: 2018/03/25 15:04:07 by aroi             ###   ########.fr       */
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
		qnt++;
		n /= 10;
	}
	return (qnt);
}

void		ft_putnbr_fd(int n, int fd)
{
	int	nbr[qnt_counter(n)];
	int i;

	i = 0;
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		if (n == -2147483648)
			ft_putstr_fd("2147483648", fd);
		n *= -1;
	}
	if (n == 0)
		ft_putchar_fd('0', fd);
	while (n > 0)
	{
		nbr[i++] = n % 10;
		n /= 10;
	}
	while (--i >= 0)
		ft_putchar_fd((char)nbr[i] + 48, fd);
}
