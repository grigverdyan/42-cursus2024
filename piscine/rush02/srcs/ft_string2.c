/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grverdya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 19:46:25 by grverdya          #+#    #+#             */
/*   Updated: 2023/10/29 23:01:17 by vkrivogo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_string.h"

char	*ft_strncpy(char *dest, char *src, int n)
{
	int	i;

	i = -1;
	while (++i < n && src[i])
		dest[i] = src[i];
	while (i < n)
		dest[i++] = '\0';
	return (dest);
}

char	*ft_strchr(const char *s, int c)
{
	if (!s)
		return (0);
	while (*s != '\0')
	{
		if (*s == (char)(c))
			return ((char *)(s));
		else
			s++;
	}
	if (c == '\0')
		return ((char *)s);
	return (0);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*ptr;
	size_t	i;
	size_t	j;

	if (!s1)
	{
		s1 = (char *)malloc(1 * sizeof(char));
		s1[0] = '\0';
	}
	if (!s1 || !s2)
		return (NULL);
	i = -1;
	j = -1;
	ptr = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(*s1));
	if (!ptr)
		return (0);
	while (s1 && s1[++i])
		ptr[i] = s1[i];
	while (s2 && s2[++j])
		ptr[i++] = s2[j];
	ptr[i] = '\0';
	free(s1);
	return (ptr);
}

char	*ft_strdup(char *s1)
{
	int		i;
	char	*dest;

	i = 0;
	while (s1[i])
		++i;
	dest = (char *) malloc(i + 1);
	if (dest == NULL)
		return (NULL);
	i = 0;
	while (s1[i] != '\0')
	{
		dest[i] = s1[i];
		++i;
	}
	dest[i] = '\0';
	return (dest);
}

void	rtrim_space(char *line, int *len)
{
	while (!(line[*len - 1] >= 33 && line[*len - 1] <= 126))
	{
		line[*len - 1] = '\0';
		*len -= 1;
	}
}
