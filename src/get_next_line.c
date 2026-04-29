/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartel <amartel@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 18:05:37 by amartel           #+#    #+#             */
/*   Updated: 2026/04/29 05:04:03 by amartel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft.h"
#include <stdio.h>

int	get_next_clean(char **stash, int fd)
{
	size_t	i;

	i = 0;
	if (fd < 0)
	{
		while (i < 1024)
		{
			free(stash[i]);
			stash[i] = NULL;
			++i;
		}
		return (-1);
	}
	else
		return (1);
}

char	*ft_extract_line(char *stash)
{
	size_t	i;
	char	*line;

	i = 0;
	while (stash[i] && stash[i] != '\n')
		++i;
	if (stash[i] == '\n')
		++i;
	line = ft_calloc(sizeof(char), (i + 1));
	if (!line)
		return (NULL);
	i = 0;
	while (stash[i])
	{
		line[i] = stash[i];
		if (stash[i] == '\n')
		{
			++i;
			break ;
		}
		++i;
	}
	return (line);
}

char	*ft_update_stash(char *stash)
{
	char	*new_stash;
	size_t	i;
	size_t	j;

	i = 0;
	while (stash[i] && stash[i] != '\n')
		++i;
	if (stash[i] == '\0')
	{
		free(stash);
		return (NULL);
	}
	++i;
	new_stash = ft_calloc(sizeof(char), (ft_strlen(&stash[i]) + 1));
	if (!new_stash)
	{
		free(stash);
		return (NULL);
	}
	j = 0;
	while (stash[i])
		new_stash[j++] = stash[i++];
	free(stash);
	return (new_stash);
}

char	*ft_process_stash(char **stash_ptr, char *buffer)
{
	char	*line;

	free(buffer);
	if (*stash_ptr == NULL || **stash_ptr == '\0')
	{
		free(*stash_ptr);
		*stash_ptr = NULL;
		return (NULL);
	}
	line = ft_extract_line(*stash_ptr);
	*stash_ptr = ft_update_stash(*stash_ptr);
	if (*stash_ptr && **stash_ptr == '\0')
	{
		free(*stash_ptr);
		*stash_ptr = NULL;
	}
	return (line);
}

char	*get_next_line(int fd)
{
	char		*buf;
	static char	*stash[1024];
	int			read_bytes;
	char		*line;
	char		*tmp;

	read_bytes = 1;
	if (get_next_clean(stash, fd) == -1)
		return (NULL);
	buf = ft_calloc(sizeof(char), (BUFFER_SIZE + 1));
	while (buf && (!stash[fd] || !ft_strchr(stash[fd], '\n')) && read_bytes > 0)
	{
		read_bytes = read(fd, buf, BUFFER_SIZE);
		if (read_bytes == -1)
		{
			free(stash[fd]);
			free(buf);
			return (NULL);
		}
		tmp = ft_strjoin(stash[fd], buf);
		free(stash[fd]);
		stash[fd] = tmp;
	}
	line = ft_process_stash(&stash[fd], buf);
	return (line);
}
