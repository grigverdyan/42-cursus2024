/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strings.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grverdya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 22:06:04 by grverdya          #+#    #+#             */
/*   Updated: 2024/01/31 19:30:29 by grverdya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

char	*ft_strchr(const char *s, int c)
{
	while (*s != '\0')
	{
		if ((unsigned char) *s == (unsigned char) c)
			return ((char *) s);
		s++;
	}
	if (c == '\0')
		return ((char *) s);
	return (NULL);
}

size_t	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

size_t	ft_putstr(char *s)
{
	size_t	len;

	if (!s)
		return (ft_putstr("(null)"));
	len = ft_strlen(s);
	write(1, s, len);
	return (len);
}

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len] != '\0')
		++len;
	return (len);
}
