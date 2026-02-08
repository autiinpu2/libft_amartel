/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dprintf.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartel <amartel@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/31 15:32:39 by amartel           #+#    #+#             */
/*   Updated: 2026/02/08 18:53:31 by amartel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_dprintf.h
 * @details All internal function of ft_dprintf
 */
#ifndef FT_DPRINTF_H
# define FT_DPRINTF_H

# ifdef __APPLE__
#  define NULL_POINTER "0x0"
#  define NULL_STR "(null)"
# else
#  define NULL_POINTER "(nil)"
#  define NULL_STR "(null)"
# endif

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>

/**
 * @brief Detect the type afer '%' characters
 * @return The lenght atfer format the string
 */
void	basic_type(va_list ap, int fd, const char *fmt, int *len);

#endif
