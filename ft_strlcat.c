/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 21:13:41 by amartel           #+#    #+#             */
/*   Updated: 2025/10/23 19:04:17 by amartel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;
	size_t	lensrc;
	size_t	lendst;

	lensrc = ft_strlen(src);
	if (dstsize == 0)
		return (lensrc);
	lendst = ft_strlen(dst);
	i = lendst;
	j = 0;
	while (src[j] && i < dstsize - 1)
	{
		dst[i] = src[j];
		j++;
		i++;
	}
	dst[i] = '\0';
	if (dstsize < lendst)
		return (lensrc + dstsize);
	return (lendst + lensrc);
}
