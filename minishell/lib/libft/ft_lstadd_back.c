/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grverdya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 15:25:17 by grverdya          #+#    #+#             */
/*   Updated: 2024/01/27 15:25:26 by grverdya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list_libft **lst, t_list_libft *new)
{
	t_list_libft	*p;

	if (lst)
	{
		if (!*lst)
			*lst = new;
		else
		{
			p = ft_lstlast(*lst);
			p->next = new;
		}
	}
}
