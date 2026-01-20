/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartel <amartel@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 12:03:29 by amartel           #+#    #+#             */
/*   Updated: 2026/01/20 13:06:21 by amartel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


/**
 * @file printf.h
 */

#ifndef PRINTF_H
# define PRINTF_H

# ifdef __APPLE__
	# define NULL_POINTER "0x0"
	# define NULL_STR "(null)"
# else
	# define NULL_POINTER "(nil)"
	# define NULL_STR "(null)"
# endif

/**
 * @brief ft_printf
 * 
 * man printf
 * @param fmt The ap for va_list
 * @param ... All value to put in ft_printf
 * @return The len of string
 */
int	ft_printf(const char *fmt, ...) __attribute__((format(printf, 1, 2)));


# endif