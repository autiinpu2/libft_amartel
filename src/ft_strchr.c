/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartel <amartel@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 21:16:32 by amartel           #+#    #+#             */
/*   Updated: 2025/11/26 15:55:31 by amartel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	const char	*ptr;

	if (!s)
		return (NULL);
	ptr = s;
	while (1)
	{
		if ((unsigned char)*ptr == (unsigned char)c)
			return ((char *)ptr);
		if ((unsigned char)*ptr == '\0')
			return (NULL);
		++ptr;
	}
}
