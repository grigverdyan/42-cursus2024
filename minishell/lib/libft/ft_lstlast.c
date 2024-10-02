/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grverdya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 15:24:55 by grverdya          #+#    #+#             */
/*   Updated: 2024/01/27 15:24:57 by grverdya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list_libft	*ft_lstlast(t_list_libft *lst)
{
	t_list_libft	*t;

	if (!lst)
		return (NULL);
	t = lst;
	while (t->next)
	{
		t = t->next;
	}
	return (t);
}
