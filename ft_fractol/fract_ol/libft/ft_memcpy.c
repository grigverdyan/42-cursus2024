/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stadevos <stadevos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 22:55:42 by stadevos          #+#    #+#             */
/*   Updated: 2022/03/20 01:44:21 by stadevos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	idx;
	char	*ptr1;
	char	*ptr2;

	idx = 0;
	ptr1 = (char *)dest;
	ptr2 = (char *)src;
	while (idx < n)
	{
		ptr1[idx] = ptr2[idx];
		idx++;
	}
	return (ptr1);
}
