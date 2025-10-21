/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 22:57:20 by amartel           #+#    #+#             */
/*   Updated: 2025/10/21 16:55:12 by amartel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char		*dest;
	size_t		i;
	size_t		lens;

	dest = NULL;
	i = 0;
	lens = ft_strlen((char *)s) + 1;
	while (i < lens)
	{
		if (s[i] == (char)c)
		{
			dest = (char *)&s[i];
		}
		i++;
	}
	return (dest);
}
