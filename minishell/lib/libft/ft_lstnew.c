/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grverdya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 15:24:05 by grverdya          #+#    #+#             */
/*   Updated: 2024/01/27 15:24:07 by grverdya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list_libft	*ft_lstnew(void *content)
{
	t_list_libft	*node;

	node = malloc(sizeof(t_list_libft));
	if (!node)
		return (NULL);
	node->content = content;
	node->next = NULL;
	return (node);
}
