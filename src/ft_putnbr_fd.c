/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartel <amartel@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 23:47:22 by amartel           #+#    #+#             */
/*   Updated: 2026/02/18 05:15:21 by amartel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	precheck(int nb, int fd, int *len)
{
	if (fd < 0)
		return (1);
	if (nb == 0)
	{
		ft_putchar_fd('0', fd);
		++*len;
		return (1);
	}
	return (0);
}

int	ft_putnbr_fd(int n, int fd)
{
	long	divider;
	long	nb;
	int		i;

	nb = n;
	divider = 1;
	i = 0;
	if (precheck(nb, fd, &i) == 1)
		return (i);
	if (nb < 0)
	{
		ft_putchar_fd('-', fd);
		nb = -nb;
	}
	while (divider * 10 <= nb)
		divider *= 10;
	while (divider > 0)
	{
		ft_putchar_fd((nb / divider + '0'), fd);
		nb %= divider;
		divider /= 10;
		++i;
	}
	return (i);
}
