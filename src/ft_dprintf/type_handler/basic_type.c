/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_type.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartel <amartel@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/31 16:06:18 by amartel           #+#    #+#             */
/*   Updated: 2026/02/01 19:16:50 by amartel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dprintf.h"
#include "libft.h"

void	basic_type(va_list ap, int fd, const char *fmt, int *len)
{
	fmt++;
	if (*fmt == 'c')
		*len += write(fd, (char []){va_arg(ap, int)}, 1);
	else if (*fmt == 's')
		*len += ft_putstr_fd(va_arg(ap, char *), fd);
	else if (*fmt == 'd' || *fmt == 'i')
		*len += ft_putnbr_fd(va_arg(ap, int), fd);
	else if (*fmt == '%')
		*len += write(fd, (char []){37}, 1);
}
