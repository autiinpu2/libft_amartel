/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartel <amartel@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 23:32:03 by amartel           #+#    #+#             */
/*   Updated: 2025/12/03 18:00:33 by amartel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	i;
	size_t	s_len;
	size_t	len_substr;

	i = 0;
	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	len_substr = 0;
	while (start + len_substr < s_len && len_substr < len)
		len_substr++;
	sub = (char *) ft_calloc(len_substr + 1, sizeof(char));
	if (!sub)
		return (NULL);
	while (i < len_substr)
	{
		sub[i] = s[start];
		i++;
		start++;
	}
	return (sub);
}
