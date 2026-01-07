/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartel <amartel@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 04:06:43 by amartel           #+#    #+#             */
/*   Updated: 2026/01/07 04:18:50 by amartel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file is.h
 */
#ifndef IS_H
# define IS_H

/**
 * @brief Checks for an alphabetic character.
 * @param c The character to test.
 * @return Non-zero if c is an alphabetic character, 0 otherwise.
 */
int			ft_isalpha(int c);

/**
 * @brief Checks for a digit (0 through 9).
 * @param c The character to test.
 * @return Non-zero if c is a digit, 0 otherwise.
 */
int			ft_isdigit(int c);

/**
 * @brief Checks for an alphanumeric character.
 * @param c The character to test.
 * @return Non-zero if c is alphanumeric, 0 otherwise.
 */
int			ft_isalnum(int c);

/**
 * @brief Checks whether c is a 7-bit unsigned char value that fits into the 
 * ASCII character set.
 * @param c The character to test.
 * @return Non-zero if c is an ASCII character, 0 otherwise.
 */
int			ft_isascii(int c);

/**
 * @brief Checks for any printable character (including space).
 * @param c The character to test.
 * @return Non-zero if c is printable, 0 otherwise.
 */
int			ft_isprint(int c);

#endif