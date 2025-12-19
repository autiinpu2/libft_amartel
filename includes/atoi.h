/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartel <amartel@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 18:10:29 by amartel           #+#    #+#             */
/*   Updated: 2025/12/20 00:04:01 by amartel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ATOI_H
# define ATOI_H

int				ft_atoi(const char *nptr);
int				ft_atoi_base(const char *nptr, char *base);
long int		ft_atol(const char *nptr);
long long int	ft_atoll(const char *nptr);

#endif