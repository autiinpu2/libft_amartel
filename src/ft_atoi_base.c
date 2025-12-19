/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartel <amartel@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 11:52:18 by amartel           #+#    #+#             */
/*   Updated: 2025/12/20 00:03:52 by amartel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "atoi.h"
#include "libft.h"

static int	get_index_in_base(char c, char *base)
{
	int	i;

	i = 0;
	while (base[i])
	{
		if (base[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

int	ft_atoi_base(const char *nptr, char *base)
{
	int	nb;
	int	i;
	int	sign;
	int	value;

	nb = 0;
	i = 0;
	sign = 1;
	while (nptr[i] == ' ' || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign *= -1;
		++i;
	}
	while (get_index_in_base(nptr[i], base) != -1)
	{
		value = get_index_in_base(nptr[i], base);
		nb = nb * ft_strlen(base) + value;
		++i;
	}
	return (sign * nb);
}

