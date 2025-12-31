/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartel <amartel@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 18:05:55 by amartel           #+#    #+#             */
/*   Updated: 2025/12/31 21:10:55 by amartel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft.h"

char	*ft_free_stash(char *stash, char *buffer)
{
	free(stash);
	free(buffer);
	stash = NULL;
	return (NULL);
}

size_t	ft_gnl_strlen(const char *str)
{
	size_t	len;

	len = 0;
	if (!str)
		return (len);
	while (str[len])
		++len;
	return (len);
}

int	get_next_clean(char **stash, int fd)
{
	size_t	i;

	i = 0;
	if (fd < 0)
	{
		while (i < 1024)
		{
			free(stash[i]);
			++i;
		}
		return (-1);
	}
	else
		return (1);
}
