/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stadevos <stadevos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 10:18:03 by stadevos          #+#    #+#             */
/*   Updated: 2022/04/02 11:02:51 by stadevos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*ptr;
	int		res;
	size_t	idx_s;
	size_t	idx_ptr;

	ptr = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!ptr)
		return (NULL);
	idx_s = 0;
	idx_ptr = 0;
	while (s[idx_s])
	{
		res = f(idx_s, s[idx_s]);
		if (res)
			ptr[idx_ptr++] = res;
		idx_s++;
	}
	ptr[idx_ptr] = '\0';
	return (ptr);
}
