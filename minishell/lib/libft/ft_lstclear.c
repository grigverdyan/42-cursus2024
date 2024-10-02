/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grverdya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 15:25:51 by grverdya          #+#    #+#             */
/*   Updated: 2024/01/28 15:38:11 by grverdya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list_libft **lst, void (*del)(void*))
{
	t_list_libft	*node;
	t_list_libft	*temp;

	if (!lst || !del)
		return ;
	temp = *lst;
	while (temp)
	{
		node = temp;
		temp = temp->next;
		ft_lstdelone(node, del);
	}
	*lst = NULL;
}
