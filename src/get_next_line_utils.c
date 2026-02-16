/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartel <amartel@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 18:05:55 by amartel           #+#    #+#             */
/*   Updated: 2026/02/16 18:07:20 by amartel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_free_stash(char *stash, char *buffer)
{
	free(stash);
	free(buffer);
	stash = NULL;
	return (NULL);
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
