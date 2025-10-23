/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 21:11:25 by amartel           #+#    #+#             */
/*   Updated: 2025/10/23 18:26:22 by amartel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char			*d;
	const char		*s;
	size_t			i;

	i = 0;
	d = (char *)dest;
	s = src;
	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
	return (d);
}
