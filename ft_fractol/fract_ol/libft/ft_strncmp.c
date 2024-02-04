/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stadevos <stadevos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 19:28:15 by stadevos          #+#    #+#             */
/*   Updated: 2022/03/20 01:46:28 by stadevos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *str1, const char *str2, size_t n)
{
	size_t			i;
	unsigned char	*ptr1;
	unsigned char	*ptr2;

	i = 0;
	ptr1 = (unsigned char *)str1;
	ptr2 = (unsigned char *)str2;
	while ((ptr1[i] || ptr2[i]) && (i < n))
	{
		if (ptr1[i] < ptr2[i])
			return (-1);
		if (ptr1[i] > ptr2[i])
			return (1);
		i++;
	}
	return (0);
}
