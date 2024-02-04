/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stadevos <stadevos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 00:23:26 by stadevos          #+#    #+#             */
/*   Updated: 2022/03/20 01:44:41 by stadevos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *str, int c, size_t n)
{
	size_t	idx;
	char	*ptr;

	idx = 0;
	ptr = (char *)str;
	while (idx < n)
	{
		ptr[idx] = (unsigned char)(c);
		idx++;
	}
	return (str);
}
