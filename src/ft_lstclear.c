/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartel <amartel@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 08:41:41 by amartel           #+#    #+#             */
/*   Updated: 2025/12/03 17:59:17 by amartel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*tmp;
	t_list	*last;

	if (!lst || !del || !*lst)
		return ;
	tmp = *lst;
	while (tmp)
	{
		last = tmp;
		tmp = tmp->next;
		del(last->content);
		free(last);
	}
	*lst = NULL;
}
