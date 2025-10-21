/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 23:32:23 by amartel           #+#    #+#             */
/*   Updated: 2025/10/18 18:54:05 by amartel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new_str;
	size_t	i;
	size_t	len_s1;
	size_t	len_s2;
	size_t	j;

	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	new_str = ft_calloc((len_s1 + len_s2 + 1), sizeof(char));
	if (!new_str)
		return (NULL);
	i = 0;
	while (i < len_s1)
	{
		new_str[i] = s1[i];
		i++;
	}
	j = 0;
	while (j < len_s2)
	{
		new_str[i++] = s2[j];
		j++;
	}
	return (new_str);
}
