/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartel <amartel@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 18:05:47 by amartel           #+#    #+#             */
/*   Updated: 2026/01/12 23:02:20 by amartel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000
# endif

/**
 * @file get_next_line.h
 */

/**
 * @brief A safe version of ft_strjoin.
 * Concatenates s1 and s2. If one of the strings is NULL, 
 * it is treated as an empty string (length 0).
 * @param s1 The first string (can be NULL).
 * @param s2 The second string (can be NULL).
 * @return A new allocated string containing s1 followed by s2.
 */
char	*ft_gnl_strjoin(char *s1, char const *s2);
/**
 * @brief Extracts the line from the stash (up to '\n').
 * 
 * Allocates memory for the line that includes the characters 
 * read up to the first newline found in the stash.
 * @param stash The static string used by get_next_line to store reading 
 * buffers.
 * @return The allocated line
 */
char	*ft_extract_line(char *stash);
/**
 * @brief Updates the stash after a line has been extracted
 * 
 * Removes the extracted line (everything up to and including '\n')
 * @param stash The static string used by get_next_line to store reading 
 * buffers
 * @return The new stash starting after the newline
 */
char	*ft_update_stash(char *stash);
/**
 * @brief Frees the stash and the temporary buffer
 * 
 * @param stash The static string used by get_next_line to store reading 
 * buffers
 * @return NULL
 */
char	*ft_free_stash(char *stash, char *buffer);
/**
 * @brief Helper function to get_next_line
 * @param stash The static array used by get_next_line to store reading buffers
 * .
 * @param buffer The buffer create by read() with the content of file decriptor
 * .
 * @return The line return by extract_line()
 */
char	*ft_process_stash(char **stash, char *buffer);
/**
 * @brief A safe version of ft_strlen for get_next_line
 * @param str The string to measure (can be NULL)
 * @return The length of the string, or 0 if str is NULL
 */
size_t	ft_gnl_strlen(const char *str);
/**
 * @brief Forces the release of the stash memory if fd is negative
 * 
 * This function handles the cleanup of static buffers
 * 
 * @param stash The static array used by get_next_line to store reading buffers
 * @param fd The file descriptor associated with the current read
 * @return -1 to indicate cleanup was performed, or 1 if fd is valid (>= 0)
 */
int		get_next_clean(char **stash, int fd);

#endif
