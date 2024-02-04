/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stadevos <stadevos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 00:06:47 by stadevos          #+#    #+#             */
/*   Updated: 2022/03/19 15:06:32 by stadevos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*occ;

	occ = NULL;
	while (*s != '\0')
	{
		if (*s == (char)(c))
			occ = ((char *)(s));
		s++;
	}
	if (c == '\0')
		return ((char *)s);
	return (occ);
}
