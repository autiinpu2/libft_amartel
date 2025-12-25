/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartel <amartel@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 18:05:37 by amartel           #+#    #+#             */
/*   Updated: 2025/12/25 18:46:13 by amartel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft.h"

char	*ft_gnl_strjoin(char *s1, const char *s2)
{
	char	*new_str;
	size_t	i;
	size_t	len_s1;

	len_s1 = ft_gnl_strlen(s1);
	new_str = malloc(sizeof(char) * (len_s1 + ft_gnl_strlen(s2) + 1));
	if (!new_str)
	{
		free(s1);
		return (NULL);
	}
	i = 0;
	while (i < len_s1)
	{
		new_str[i] = s1[i];
		++i;
	}
	while (*s2)
		new_str[i++] = *s2++;
	new_str[i] = '\0';
	free(s1);
	return (new_str);
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
	line = malloc(sizeof(char) * (i + 1));
	if (!line)
		return (NULL);
	i = 0;
	while (stash[i] && stash[i] != '\n')
	{
		line[i] = stash[i];
		++i;
	}
	if (stash[i] == '\n')
	{
		line[i] = stash[i];
		++i;
	}
	line[i] = '\0';
	return (line);
}

char	*ft_upadate_stash(char *stash)
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
	new_stash = malloc(sizeof(char) * (ft_gnl_strlen(&stash[i]) + 1));
	if (!new_stash)
	{
		free(stash);
		return (NULL);
	}
	j = 0;
	while (stash[i])
		new_stash[j++] = stash[i++];
	new_stash[j] = '\0';
	free(stash);
	return (new_stash);
}

char	*ft_process_stash(char **stash_ptr, char *buffer)
{
	char	*line;

	if (*stash_ptr == NULL || **stash_ptr == '\0')
	{
		*stash_ptr = ft_free_stash(*stash_ptr, buffer);
		return (NULL);
	}
	free(buffer);
	line = ft_extract_line(*stash_ptr);
	*stash_ptr = ft_upadate_stash(*stash_ptr);
	return (line);
}

char	*get_next_line(int fd)
{
	char		*buffer;
	static char	*stash[1024];
	int			read_bytes;
	char		*line;

	read_bytes = 1;
	if (fd < 0)
		get_next_clean(stash);
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	while (ft_strchr(stash[fd], '\n') == NULL && read_bytes > 0)
	{
		read_bytes = read(fd, buffer, BUFFER_SIZE);
		if (read_bytes == -1)
		{
			stash[fd] = ft_free_stash(stash[fd], buffer);
			return (NULL);
		}
		buffer[read_bytes] = '\0';
		stash[fd] = ft_gnl_strjoin(stash[fd], buffer);
	}
	line = ft_process_stash(&stash[fd], buffer);
	return (line);
}
