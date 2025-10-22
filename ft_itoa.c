/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 23:33:14 by amartel           #+#    #+#             */
/*   Updated: 2025/10/22 04:30:05 by amartel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include "libft.h"
size_t	count_bits(long n) {
	size_t count = 0;
	if (n == 0 || n < 0)
		count++;
	while (n) {
		n = n / 10;
		count++;
	}
	return count;
}

char	*ft_itoa(int n)
{
	char	*s;
	size_t	count;
	long	longn;

	longn = n;
	count = count_bits(longn);
	s = ft_calloc(count + 1, sizeof(char));
	if (!s)
		return (NULL);
	if (longn == 0)
		s[0] = '0';
	if (n < 0) {
		s[0] = '-';
		longn = -longn;
	}
	while (longn) {
		count--;
		s[count] = longn % 10 + '0';
		longn = longn / 10;
	}
	return (s);
}