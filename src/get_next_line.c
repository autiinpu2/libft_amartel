/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartel <amartel@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 18:05:37 by amartel           #+#    #+#             */
/*   Updated: 2025/12/03 18:00:44 by amartel          ###   ########.fr       */
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

char	*ft_extract_line(char *stach)
{
	size_t	i;
	char	*line;

	i = 0;
	while (stach[i] && stach[i] != '\n')
		++i;
	if (stach[i] == '\n')
		++i;
	line = malloc(sizeof(char) * (i + 1));
	if (!line)
		return (NULL);
	i = 0;
	while (stach[i] && stach[i] != '\n')
	{
		line[i] = stach[i];
		++i;
	}
	if (stach[i] == '\n')
	{
		line[i] = stach[i];
		++i;
	}
	line[i] = '\0';
	return (line);
}

char	*ft_upadate_stach(char *stach)
{
	char	*new_stach;
	size_t	i;
	size_t	j;

	i = 0;
	while (stach[i] && stach[i] != '\n')
		++i;
	if (stach[i] == '\0')
	{
		free(stach);
		return (NULL);
	}
	++i;
	new_stach = malloc(sizeof(char) * (ft_gnl_strlen(&stach[i]) + 1));
	if (!new_stach)
	{
		free(stach);
		return (NULL);
	}
	j = 0;
	while (stach[i])
		new_stach[j++] = stach[i++];
	new_stach[j] = '\0';
	free(stach);
	return (new_stach);
}

char	*ft_process_stach(char **stach_ptr, char *buffer)
{
	char	*line;

	if (*stach_ptr == NULL || **stach_ptr == '\0')
	{
		*stach_ptr = ft_free_stach(*stach_ptr, buffer);
		return (NULL);
	}
	free(buffer);
	line = ft_extract_line(*stach_ptr);
	*stach_ptr = ft_upadate_stach(*stach_ptr);
	return (line);
}

char	*get_next_line(int fd)
{
	char		*buffer;
	static char	*stach[1024];
	int			read_bytes;
	char		*line;

	read_bytes = 1;
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	while (ft_strchr(stach[fd], '\n') == NULL && read_bytes > 0)
	{
		read_bytes = read(fd, buffer, BUFFER_SIZE);
		if (read_bytes == -1)
		{
			stach[fd] = ft_free_stach(stach[fd], buffer);
			return (NULL);
		}
		buffer[read_bytes] = '\0';
		stach[fd] = ft_gnl_strjoin(stach[fd], buffer);
	}
	line = ft_process_stach(&stach[fd], buffer);
	return (line);
}
