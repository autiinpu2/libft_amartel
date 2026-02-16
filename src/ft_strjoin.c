/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartel <amartel@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 23:32:23 by amartel           #+#    #+#             */
/*   Updated: 2026/02/16 21:31:38 by amartel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char *s1, char *s2)
{
	char	*new_str;
	size_t	i;

	if (!s1)
		s1 = ft_calloc(1, sizeof(char));
	else if (!s1 && !s2)
		return (NULL);
	else if (!s1)
		return (s2);
	else if (!s2)
		return (s1);
	new_str = ft_calloc((ft_strlen(s1) + ft_strlen(s2) + 1), sizeof(char));
	if (!new_str)
	{
		free(s1);
		return (NULL);
	}
	i = -1;
	while (s1[++i])
		new_str[i] = s1[i];
	while (*s2)
		new_str[i++] = *s2++;
	free(s1);
	return (new_str);
}
