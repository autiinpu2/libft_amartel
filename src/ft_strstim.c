/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 23:32:43 by amartel           #+#    #+#             */
/*   Updated: 2025/10/17 17:52:35 by amartel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

char *ft_strtrim(char const *s1, char const *set) {
	char *new_s;
	size_t len_set;
	size_t len_s;


	len_set = ft_strlen(set);
	len_s = ft_strlen(s1);
	new_s = (char *)ft_calloc((len_s - (len_set * 2) + 1), sizeof(char));
	if (!new_s)
		return (NULL);
	
}
