/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartel <amartel@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/31 15:31:24 by amartel           #+#    #+#             */
/*   Updated: 2026/02/01 19:17:48 by amartel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_dprintf.h"

int	ft_dprintf(int fd, const char *fmt, ...)
{
	va_list	ap;
	int		len;
	size_t	i;

	len = 0;
	i = 0;
	if (!fmt)
		return (-1);
	va_start(ap, fmt);
	while (fmt[i])
	{
		if (fmt[i] == '%')
		{
			basic_type(ap, fd, &fmt[i], &len);
			i += 2;
		}
		else
			len += write(fd, &fmt[i++], 1);
	}
	va_end(ap);
	return (len);
}
