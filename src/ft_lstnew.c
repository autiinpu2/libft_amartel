/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartel <amartel@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 17:37:51 by amartel           #+#    #+#             */
/*   Updated: 2025/12/03 17:59:28 by amartel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*new_lst;

	new_lst = ft_calloc(1, sizeof(t_list));
	if (!new_lst)
		return (NULL);
	new_lst->content = content;
	return (new_lst);
}
