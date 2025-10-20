/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 22:57:20 by amartel           #+#    #+#             */
/*   Updated: 2025/10/17 19:39:49 by amartel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*ptr;
	size_t	i;

	i = ft_strlen(s);
	ptr = (char *)s;
	while (i > 0)
	{
		if ((unsigned char)ptr[i] == (unsigned char)c)
			return (&ptr[i]);
		--i;
	}
	return (NULL);
}
