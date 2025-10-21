/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 22:59:04 by amartel           #+#    #+#             */
/*   Updated: 2025/10/17 20:03:56 by amartel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t size)
{
	size_t	i;
	size_t	j;
	char	*str;

	str = (char *)big;
	i = 0;
	j = 0;
	if ((!big && !size) || !str)
		return (NULL);
	if (little[0] == '\0')
		return (str);
	while (str[i] != '\0' && i < size)
	{
		j = 0;
		while (little[j] && i + j < size && str[i + j] == little[j])
			j++;
		if (little[j] == '\0')
			return (str + i);
		i++;
	}
	return (NULL);
}
