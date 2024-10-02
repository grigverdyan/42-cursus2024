/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grverdya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 15:24:41 by grverdya          #+#    #+#             */
/*   Updated: 2024/08/28 20:30:52 by grverdya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list_libft *lst)
{
	int				len;
	t_list_libft	*temp;

	if (!lst)
		return (0);
	len = 1;
	temp = lst;
	while (lst->next)
	{
		len++;
		lst = lst->next;
	}
	lst = temp;
	return (len);
}
