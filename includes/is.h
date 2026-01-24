/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartel <amartel@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 04:06:43 by amartel           #+#    #+#             */
/*   Updated: 2026/01/24 21:51:58 by amartel          ###   ########.fr       */
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
 * @return true if c is an alphabetic character, false otherwise.
 */
bool	ft_isalpha(const int c);

/**
 * @brief Checks for a digit (0 through 9).
 * @param c The character to test.
 * @return true if c is a digit, false otherwise.
 */
bool	ft_isdigit(const int c);

/**
 * @brief Checks for an alphanumeric character.
 * @param c The character to test.
 * @return true if c is alphanumeric, false otherwise.
 */
bool	ft_isalnum(const int c);

/**
 * @brief Checks whether c is a 7-bit unsigned char value that fits into the 
 * ASCII character set.
 * @param c The character to test.
 * @return true if c is an ASCII character, false otherwise.
 */
bool	ft_isascii(const int c);

/**
 * @brief Checks for any printable character (including space).
 * @param c The character to test.
 * @return true if c is printable, false otherwise.
 */
bool	ft_isprint(const int c);

/**
 * @brief Checks for an speace character
 * @param c thes character to test.
 * @return true if c is space, false otherwise.
 */
bool	ft_isspace(const int c);

#endif
