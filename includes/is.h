/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apuyane <apuyane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 04:06:43 by amartel           #+#    #+#             */
/*   Updated: 2026/01/21 14:41:27 by apuyane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file is.h
 */
#ifndef IS_H
# define IS_H

# include "libft.h"

/**
 * @brief Checks for an alphabetic character.
 * @param c The character to test.
 * @return Non-zero if c is an alphabetic character, 0 otherwise.
 */
bool	ft_isalpha(const int c);

/**
 * @brief Checks for a digit (0 through 9).
 * @param c The character to test.
 * @return Non-zero if c is a digit, 0 otherwise.
 */
bool	ft_isdigit(const int c);

/**
 * @brief Checks for an alphanumeric character.
 * @param c The character to test.
 * @return Non-zero if c is alphanumeric, 0 otherwise.
 */
bool	ft_isalnum(const int c);

/**
 * @brief Checks whether c is a 7-bit unsigned char value that fits into the 
 * ASCII character set.
 * @param c The character to test.
 * @return Non-zero if c is an ASCII character, 0 otherwise.
 */
bool	ft_isascii(const int c);

/**
 * @brief Checks for any printable character (including space).
 * @param c The character to test.
 * @return Non-zero if c is printable, 0 otherwise.
 */
bool	ft_isprint(const int c);

/**
 * @brief
 * @param
 * @return
 */
bool ft_isspace(const int c);

#endif
