/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stadevos <stadevos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 04:37:47 by stadevos          #+#    #+#             */
/*   Updated: 2022/04/02 06:48:01 by stadevos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	checker(char s1, char const *set)
{
	size_t	idx;

	idx = 0;
	while (set[idx])
	{
		if (s1 == set[idx])
			return (1);
		else
			idx++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*ptr;
	size_t	start;
	size_t	end;

	start = 0;
	end = ft_strlen(s1);
	while (s1[start] && checker(s1[start], set))
		start++;
	while (end > start && checker(s1[end - 1], set))
		end--;
	ptr = ft_substr(s1, start, end - start);
	return (ptr);
}
