/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 21:16:32 by amartel           #+#    #+#             */
/*   Updated: 2025/10/17 19:54:02 by amartel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*ptr;
	int		i;

	i = 0;
	ptr = (char *)s;
	while (ptr[i])
	{
		if ((unsigned char)ptr[i] == (unsigned char)c)
			return (ptr + i);
		++i;
	}
	if ((unsigned char)ptr[i] == (unsigned char)c)
		return (ptr + i);
	return (NULL);
}
