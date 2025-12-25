/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartel <amartel@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 18:05:47 by amartel           #+#    #+#             */
/*   Updated: 2025/12/25 18:45:50 by amartel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

char	*get_next_line(int fd);
char	*ft_gnl_strjoin(char *s1, char const *s2);
char	*ft_extract_line(char *stash);
char	*ft_upadate_stash(char *stash);
char	*ft_free_stash(char *stash, char *buffer);
char	*ft_process_stash(char **stash, char *buffer);
size_t	ft_gnl_strlen(const char *str);
void	get_next_clean(char **stash);

#endif
