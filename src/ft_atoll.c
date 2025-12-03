/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoll.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartel <amartel@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 18:01:45 by amartel           #+#    #+#             */
/*   Updated: 2025/12/03 18:14:17 by amartel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "atoi.h"

long long int	ft_atoll(const char *nptr)
{
	long long int	nb;
	int				i;
	int				sign;

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
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		nb = nb * 10 + (nptr[i] - '0');
		++i;
	}
	return (sign * nb);
}
