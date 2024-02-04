/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stadevos <stadevos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 01:47:41 by stadevos          #+#    #+#             */
/*   Updated: 2022/03/20 02:05:35 by stadevos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			idx;
	unsigned char	*ptr1;
	unsigned char	*ptr2;

	idx = 0;
	ptr1 = (unsigned char *)s1;
	ptr2 = (unsigned char *)s2;
	while (idx < n)
	{
		if (ptr1[idx] != ptr2[idx])
			return (ptr1[idx] - ptr2[idx]);
		idx++;
	}
	return (0);
}
