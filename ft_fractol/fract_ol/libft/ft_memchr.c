/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stadevos <stadevos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 00:32:15 by stadevos          #+#    #+#             */
/*   Updated: 2022/03/20 01:24:13 by stadevos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str, int c, size_t n)
{
	size_t			idx;
	unsigned char	*ptr;

	idx = 0;
	ptr = (unsigned char *)str;
	while (idx < n)
	{
		if (ptr[idx] == (unsigned char)c)
			return ((void *)ptr + idx);
		idx++;
	}
	return (NULL);
}
