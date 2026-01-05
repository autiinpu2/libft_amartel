/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartel <amartel@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 18:10:29 by amartel           #+#    #+#             */
/*   Updated: 2026/01/05 05:51:23 by amartel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ATOI_H
# define ATOI_H

/**
 * @file atoi.h
 */

/**
 * @brief acsii to int
 * 
 * function for convert string to int
 * @param nptr string
 * @return the convert integer
 * @warning Overflow your int if your param is upper than INT_MAX or less
 * than INT_MIN
 */
int				ft_atoi(const char *nptr);
/**
 * @brief acsii to int with base
 * 
 * function for convert string to int
 * @param nptr string
 * @return the convert integer
 * @warning Overflow your int if your param is upper than INT_MAX or less
 * than INT_MIN and your base is not check
 */
int				ft_atoi_base(const char *nptr, char *base);
/**
 * @brief acsii to long
 * 
 * function for convert string to long
 * @param nptr string
 * @return the convert integer
 * @warning Overflow your int if your param is upper than LONG_MAX or less
 * than LONG_MIN
 */
long int		ft_atol(const char *nptr);
/**
 * @brief acsii to long int
 * 
 * function for convert string to long long
 * @param nptr string
 * @return the convert integer
 * @warning Overflow your int if your param is upper than LLONG_MAX or less
 * than LLONG_MIN
 */
long long int	ft_atoll(const char *nptr);

#endif