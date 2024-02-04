/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stadevos <stadevos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 20:29:41 by stadevos          #+#    #+#             */
/*   Updated: 2022/04/06 20:29:43 by stadevos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;
	t_list	*node;

	new_lst = ft_lstnew(f(lst->content));
	if (!new_lst)
		return (NULL);
	node = new_lst;
	lst = lst->next;
	while (lst)
	{
		new_lst = ft_lstnew(f(lst->content));
		if (!new_lst)
			ft_lstclear(&new_lst, del);
		ft_lstadd_back(&node, new_lst);
		lst = lst->next;
	}
	return (node);
}
