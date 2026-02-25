/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartel <amartel@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 04:58:25 by amartel           #+#    #+#             */
/*   Updated: 2026/02/25 21:59:31 by amartel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(int n)
{
	long	divider;
	long	nb;
	char	c;

	nb = n;
	divider = 1;
	if (nb < 0)
	{
		(void) write(1, "-", 1);
		nb = -nb;
	}
	if (nb == 0)
	{
		(void) write(1, "0", 1);
		return ;
	}
	while (divider * 10 <= nb)
		divider *= 10;
	while (divider > 0)
	{
		c = nb / divider + '0';
		(void) write(1, &c, 1);
		nb %= divider;
		divider /= 10;
	}
}
