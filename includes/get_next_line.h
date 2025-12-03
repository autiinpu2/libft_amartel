/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartel <amartel@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 18:05:47 by amartel           #+#    #+#             */
/*   Updated: 2025/12/03 18:07:39 by amartel          ###   ########.fr       */
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
char	*ft_extract_line(char *stach);
char	*ft_upadate_stach(char *stach);
char	*ft_free_stach(char *stach, char *buffer);
char	*ft_process_stach(char **stach, char *buffer);
size_t	ft_gnl_strlen(const char *str);

#endif
