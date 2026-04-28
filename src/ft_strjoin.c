/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartel <amartel@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 23:32:23 by amartel           #+#    #+#             */
/*   Updated: 2026/04/28 04:33:19 by amartel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*new_str;
	size_t	i;

	if (!s1 && !s2)
		return (NULL);
	new_str = ft_calloc((ft_strlen(s1) + ft_strlen(s2) + 1), sizeof(char));
	if (!new_str)
		return (NULL);
	i = -1;
	while (s1 && s1[++i])
		new_str[i] = s1[i];
	while (s2 && *s2)
		new_str[i++] = *s2++;
	return (new_str);
}
