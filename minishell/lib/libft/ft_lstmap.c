/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grverdya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 15:26:38 by grverdya          #+#    #+#             */
/*   Updated: 2024/08/28 20:30:38 by grverdya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list_libft	*ft_lstmap(t_list_libft *lst, void *(*f)(void *),
					void (*del)(void *))
{
	t_list_libft	*new_lst;
	t_list_libft	*node;

	if (!lst || !del)
		return (NULL);
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
