/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grverdya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 16:35:08 by grverdya          #+#    #+#             */
/*   Updated: 2024/02/27 21:55:36 by grverdya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *c)
{
	int	len;

	len = 0;
	while (c && c[len] != '\0')
		len++;
	return (len);
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
	int		i;
	int		j;

	if (!s1)
	{
		s1 = (char *)malloc(sizeof(char));
		s1[0] = '\0';
	}
	if (!s1 || !s2)
		return (NULL);
	i = -1;
	j = -1;
	ptr = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
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
/* 
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	s_len;
	size_t	i;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	if (len > s_len - start)
		len = s_len - start;
	if (s_len < start)
		len = 0;
	sub = (char *)malloc((len + 1) * sizeof(char));
	if (!sub)
		return (NULL);
	i = 0;
	while (s[start] && i < len)
	{
		sub[i++] = s[start];
		start++;
	}
	sub[i] = '\0';
	return (sub);
}

*/

static void	get_substr(char const *s, unsigned int start, size_t len, char *sub)
{
	size_t	i;

	i = 0;
	while (s[start] && i < len)
	{
		sub[i++] = s[start];
		start++;
	}
	sub[i] = '\0';
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	s_len;
	size_t	i;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	if (len > s_len - start)
		len = s_len - start;
	i = 0;
	if (s_len < start)
	{
		sub = (char *)malloc(sizeof(char));
		if (!sub)
			return (NULL);
		sub[i] = '\0';
		return (sub);
	}
	sub = (char *)malloc((len + 1) * sizeof(char));
	if (!sub)
		return (NULL);
	get_substr(s, start, len, sub);
	return (sub);
}

char	*ft_strdup(const char *s)
{
	char	*str;
	size_t	s_len;
	size_t	i;

	s_len = ft_strlen(s);
	str = (char *)malloc((s_len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	i = 0;
	while (i < s_len)
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
