/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartel <amartel@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 18:05:47 by amartel           #+#    #+#             */
/*   Updated: 2026/02/16 20:42:33 by amartel          ###   ########.fr       */
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
