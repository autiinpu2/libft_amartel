/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartel <amartel@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 18:10:29 by amartel           #+#    #+#             */
/*   Updated: 2025/12/16 11:52:05 by amartel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ATOI_H
# define ATOI_H

int				ft_atoi(const char *nptr);
int				ft_atoi_base(const char *nptr, const char *base);
long int		ft_atol(const char *nptr);
long long int	ft_atoll(const char *nptr);

#endif