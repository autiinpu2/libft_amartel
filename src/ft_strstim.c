/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 23:32:43 by amartel           #+#    #+#             */
/*   Updated: 2025/10/19 18:47:34 by amartel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

static int in_set(char c, char const *set)
{
	int i = 0;
	while (set[i])
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

char *ft_strtrim(char const *s1, char const *set)
{
	size_t i;
	size_t j;
	char *new_str;

	if (!s1 || !set)
		return (NULL);
	i = 0;
	while (s1[i] && in_set(s1[i], set))
		i++;
	j = ft_strlen(s1);
	while (j > i && in_set(s1[j - 1], set))
		j--;
	new_str = ft_substr(s1, i, j - i);
	return (new_str);
}
