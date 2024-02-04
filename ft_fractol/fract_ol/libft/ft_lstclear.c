/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stadevos <stadevos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 18:27:46 by stadevos          #+#    #+#             */
/*   Updated: 2022/03/20 19:53:08 by stadevos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*node;
	t_list	*tmp;

	tmp = *lst;
	if (!lst || !del)
		return ;
	while (tmp)
	{
		node = tmp;
		tmp = tmp->next;
		ft_lstdelone(node, del);
	}
	*lst = NULL;
}
