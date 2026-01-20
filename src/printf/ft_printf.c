/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartel <amartel@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 12:16:29 by amartel           #+#    #+#             */
/*   Updated: 2026/01/20 13:03:49 by amartel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	ft_printf(const char *fmt, ...)
{
	va_list	ap;
	size_t	len;
	size_t	i;

	len = 0;
	i = 0;
	if (!fmt)
		return (-1);
	va_start(ap, fmt);
	//init_flags();
	while (fmt[i])
	{
		++i;
	}
	return((int)len);
}
